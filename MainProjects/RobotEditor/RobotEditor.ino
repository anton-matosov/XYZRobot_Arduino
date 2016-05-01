#include <A1-16.h>
#include <BOLIDE_Player.h>
#include "mask_definition.h"

//definition of struct
typedef struct
{
    unsigned char pose;         // index of pose to transition to 
    int time;                   // time for transition
} sp_trans_t;
//definition of global variable
BOLIDE_Player BOLIDE_Robot;
static boolean packet_timeout_status = false;
// pose and sequence storage
static int poses[max_pose_index][MAX_SERVOS];      // poses [index][servo_id-1], check for the motion index!!
static int pose_index[max_pose_index];
sp_trans_t sequence[max_seq_index];               // sequence

void setup()
{
    Serial.begin(115200);
    BOLIDE_Robot.setup(115200, 18);
    TIMER4_task_setup();
    delay(1000);
}

void loop()
{
    static int pBuffer[128] = {0};
    static unsigned char pIndex = 0, pLength = 0xFF, pCMD = 0x00;
    static unsigned char motor_ID = 0;
    static int position_ID = 0;
    static int seq_pPoseCnt = 0xFF, PoseCnt = 0;
    static int seq_pSeqCnt = 0xFF, SeqCnt = 0;
    static int SeqPos = 0;
    static int SeqProcessCnt = 0;
    static boolean seq_trigger = false, seq_loop_trigger = false;
    static int _temp;

    _header_check:
    while ((_temp = Serial.read()) == -1)
    {
        if (seq_trigger)
        {
            static int _i = 0;
            static int pose_index = 0;
            pose_index = sequence[SeqPos].pose;
            for (_i = 0; _i < BOLIDE_Robot.poseSize; _i++)
            {
                BOLIDE_Robot.setNextPose(_i + 1, poses[pose_index][_i]);
            }
            BOLIDE_Robot.interpolateSetup(sequence[SeqPos].time);
            while (BOLIDE_Robot.interpolating)
            {
                BOLIDE_Robot.interpolateStep();
            }
            SeqPos++;
            if (SeqPos == seq_pSeqCnt)
            {
                SeqPos = 0;
                if (seq_loop_trigger)
                {
                }
                else
                {
                    seq_trigger = false;
                    seq_pSeqCnt = 0xFF;
                }
            }
        }
    }
    if (_temp == packet_header)
    {
        goto _packet_start;
    }
    goto _header_check;
    _packet_start:
    pBuffer[header_address] = _temp;
    pIndex = 1;
    _enable_timer4();
    _reset_timer4();
    packet_timeout_status = false;
    while ((_temp = Serial.read()) == -1)
    {
        if (packet_timeout_status)
        {
            packet_error_feedback(0x00);
            goto _header_check;
        }
    }
    pBuffer[length_address] = _temp;
    pLength = _temp;
    pIndex++;
    _reset_timer4();
    packet_timeout_status = false;
    while ((_temp = Serial.read()) == -1)
    {
        if (packet_timeout_status)
        {
            packet_error_feedback(0x00);
            goto _header_check;
        }
    }
    pBuffer[CMD_address] = _temp;
    pCMD = _temp;
    pIndex++;
    _reset_timer4();
    packet_timeout_status = false;
    while (1)
    {
        while ((_temp = Serial.read()) == -1)
        {
            if (packet_timeout_status)
            {
                packet_error_feedback(0x00);
                goto _header_check;
            }
        }
        pBuffer[pIndex] = _temp;
        pIndex++;
        _reset_timer4();
        packet_timeout_status = false;
        if (pIndex == pLength)
        {
            clear_buffer();
            _disable_timer4();
            _reset_timer4();
            goto _packet_finish;
        }
    }
    _packet_finish:
    if (pBuffer[pIndex - 1] == packet_tail)
    {     // check motor tail
        if (pCMD == CMD_init_motor)
        {
            seq_trigger = false;
            SeqPos = 0;
            BOLIDE_Robot.poseSize = pBuffer[motor_num_address];
            BOLIDE_Robot.readPose();
            packet_init(pBuffer[motor_num_address]);
        }
        else if (pCMD == CMD_set_motor)
        {         // set motor position
            seq_trigger = false;
            SeqPos = 0;
            motor_ID = pBuffer[motor_ID_address];
            position_ID = (pBuffer[motor_pos_msb] << 8) + pBuffer[motor_pos_lsb];
            SetPositionI_JOG(motor_ID, 0x00, position_ID);
            packet_set(motor_ID, position_ID);
        }
        else if (pCMD == CMD_capture_motor)
        {            // get motor position
            seq_trigger = false;
            SeqPos = 0;
            motor_ID = pBuffer[motor_ID_address];
            packet_capture(motor_ID);
        }
        else if (pCMD == CMD_relax_motor)
        {              // relax motor
            seq_trigger = false;
            SeqPos = 0;
            motor_ID = pBuffer[motor_ID_address];
            A1_16_TorqueOff(motor_ID);
            packet_relax(motor_ID);
        }
        else if (pCMD == CMD_SEQ_load_PoseCnt)
        {         // load total pose number
            seq_trigger = false;
            SeqPos = 0;
            seq_pPoseCnt = pBuffer[seq_pose_cnt_address];
            if (seq_pPoseCnt > max_pose_index)
            {
                packet_error_feedback(0x00);
            }
            else
            {
                packet_error_feedback(0x01);
                SeqProcessCnt = SEQ_Process_load_PoseCnt;
                seq_loop_trigger = false;
            }
        }
        else if (pCMD == CMD_SEQ_loop_load_PoseCnt)
        {    // load loop sequence pose number
            seq_trigger = false;
            SeqPos = 0;
            seq_pPoseCnt = pBuffer[seq_pose_cnt_address];
            if (seq_pPoseCnt > max_pose_index)
            {
                packet_error_feedback(0x00);
            }
            else
            {
                packet_error_feedback(0x01);
                SeqProcessCnt = SEQ_Process_load_PoseCnt;
                seq_loop_trigger = true;
            }
        }
        else if (pCMD == CMD_SEQ_load_Pose)
        {            // load pose in sequence
            static int PoseID = 0, _i = 0;
            seq_trigger = false;
            SeqPos = 0;
            if (SeqProcessCnt == SEQ_Process_load_PoseCnt)
            {
                PoseID = pBuffer[seq_pose_ID_address];
                for (_i = 0; _i < BOLIDE_Robot.poseSize; _i++)
                {
                    poses[PoseCnt][_i] = (pBuffer[seq_pose_start_address + 2 * _i] << 8) + pBuffer[seq_pose_start_address + 1 + 2 * _i];
                    pose_index[PoseCnt] = PoseID;
                }
                PoseCnt++;
                if (PoseCnt == seq_pPoseCnt)
                {
                    packet_error_feedback(0x02);
                    PoseCnt = 0;
                    SeqProcessCnt = SEQ_Process_load_Pose;
                }
                else
                {
                    packet_error_feedback(0x01);
                }
            }
            else
            {
                packet_error_feedback(0x00);
            }
        }
        else if (pCMD == CMD_SEQ_load_SEQCnt)
        {           // load total sequence number
            seq_trigger = false;
            SeqPos = 0;
            if (SeqProcessCnt == SEQ_Process_load_Pose)
            {
                seq_pSeqCnt = pBuffer[seq_seq_cnt_address];
                if (seq_pSeqCnt > max_seq_index)
                {
                    packet_error_feedback(0x00);
                }
                else
                {
                    packet_error_feedback(0x01);
                    SeqProcessCnt = SEQ_Process_load_SEQCnt;
                }
            }
            else
            {
                packet_error_feedback(0x00);
            }
        }
        else if (pCMD == CMD_SEQ_load_SEQ)
        {
            static int sPoseID = 0, sTime = 0, _i;
            seq_trigger = false;
            SeqPos = 0;
            if (SeqProcessCnt == SEQ_Process_load_SEQCnt)
            {
                sPoseID = pBuffer[seq_pose_name_address];
                sTime = (pBuffer[seq_pose_time_MSB_address] << 8) + pBuffer[seq_pose_time_LSB_address];
                for (_i = 0; _i < max_pose_index; _i++)
                {
                    if (pose_index[_i] == sPoseID)
                    {
                        sequence[SeqCnt].pose = _i;
                        sequence[SeqCnt].time = sTime;
                        SeqCnt++;
                        break;
                    }
                }
                if (SeqCnt == seq_pSeqCnt)
                {
                    packet_error_feedback(0x02);
                    SeqCnt = 0;
                    seq_trigger = true;
                    SeqProcessCnt = SEQ_Process_load_SEQ;
                }
                else
                {
                    packet_error_feedback(0x01);
                }
            }
            else
            {
                packet_error_feedback(0x00);
            }
        }
        else if (pCMD == CMD_SEQ_halt)
        {
            seq_trigger = false;
        }
        else if (pCMD == CMD_SEQ_relax)
        {
            seq_trigger = false;
            A1_16_TorqueOff(A1_16_Broadcast_ID);
        }
    }
    else
    {
        packet_error_feedback(0x00);
        pLength = 0xFF;
    }
}

//----------------     function    ----------------
void packet_init(unsigned char motor_num)
{
    Serial.write(packet_header);
    Serial.write(0x05);
    Serial.write(CMD_init_motor);
    Serial.write(motor_num);
    Serial.write(packet_tail);
}

void packet_set(unsigned char motor_ID, int pos_set)
{
    Serial.write(packet_header);
    Serial.write(0x07);
    Serial.write(CMD_set_motor);
    Serial.write(motor_ID);
    Serial.write(((pos_set & 0xFF00) >> 8));
    Serial.write((pos_set & 0x00FF));
    Serial.write(packet_tail);
}

void packet_capture(unsigned char motor_ID)
{
    static int position_buffer[19] = {0};      // position buffer
    static int _i = 0;
    for (_i = 1; _i < 19; _i++)
    {
        position_buffer[_i] = ReadPosition(_i);
    }
    Serial.write(packet_header);
    Serial.write(0x29);
    Serial.write(CMD_capture_motor);
    Serial.write(motor_ID);
    for (_i = 1; _i < 19; _i++)
    {
        Serial.write(((position_buffer[_i] & 0xFF00) >> 8));
        Serial.write((position_buffer[_i] & 0x00FF));
    }
    Serial.write(packet_tail);
}

void packet_relax(unsigned char motor_ID)
{
    Serial.write(packet_header);
    Serial.write(0x05);
    Serial.write(CMD_relax_motor);
    Serial.write(motor_ID);
    Serial.write(packet_tail);
}

void packet_error_feedback(unsigned char CMD_reaction)
{
    Serial.write(packet_header);
    Serial.write(0x04);
    Serial.write(CMD_reaction);
    Serial.write(packet_tail);
}

//----------------    Timer4 function    ----------------
void TIMER4_task_setup()
{
    TCCR4A = 0x00;                // Normal mode, just as a Timer
    TCCR4B |= _BV(CS42);          // prescaler = CPU clock/1024
    TCCR4B &= ~_BV(CS41);
    TCCR4B |= _BV(CS40);
    TCNT4 = timeout_limit;
}

ISR(TIMER4_OVF_vect)
{
    packet_timeout_status = true;
    TCNT4 = timeout_limit;
}

//----------------    Timeout function    ----------------
void clear_buffer(void)
{
    while (Serial.read() != -1)
    {
    }
}
