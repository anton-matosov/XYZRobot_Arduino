//
// Created by Anton Matosov on 4/30/16.
//

#include "MotionEditor.h"

#include <EEPROM.h>
#include <Wire.h>
#include <Arduino.h>
#include <HALArduino.h>
#include "Y-01_Board.h"
#include "Y-01_Mask_Definition.h"
#include "Y-01_USER_MOTION.h"

// TODO: Members candidates
extern BOLIDE_Player XYZrobot;

bool MotionEditor::seq_trigger = false;
bool MotionEditor::packet_timeout_status = false;

//Motion Editor Parameter
static bool seq_loop_trigger = false;
static int seq_pSeqCnt = 0xFF, SeqPos = 0x00;
static int poses[max_pose_index][MAX_SERVOS];      // poses [index][servo_id-1], check for the motion index!!
static int pose_index[max_pose_index];
sp_trans_t sequence[max_seq_index];// sequence


void cb_USB(void)
{
    while (Serial.read() != -1)
    {
    }
    //clear USB serial buffer
}


void Packet_Init(unsigned char motor_num)
{
    Serial.write(packet_header);
    Serial.write(0x05);
    Serial.write(CMD_init_motor);
    Serial.write(motor_num);
    Serial.write(packet_tail);
}

void Packet_Set(unsigned char motor_ID, int pos_set)
{
    Serial.write(packet_header);
    Serial.write(0x07);
    Serial.write(CMD_set_motor);
    Serial.write(motor_ID);
    Serial.write(((pos_set & 0xFF00) >> 8));
    Serial.write((pos_set & 0x00FF));
    Serial.write(packet_tail);
}

void Packet_Capture(unsigned char motor_ID)
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

void Packet_Relax(unsigned char motor_ID)
{
    Serial.write(packet_header);
    Serial.write(0x05);
    Serial.write(CMD_relax_motor);
    Serial.write(motor_ID);
    Serial.write(packet_tail);
}

void Packet_SN(void)
{
    static int _i = 0;
    Serial.write(packet_header);
    Serial.write(0x12);
    Serial.write(CMD_SN_read);
    for (_i = 10; _i < 24; _i++)
    {
        Serial.write(EEPROM.read(_i));
    }
    Serial.write(packet_tail);
}

void Packet_Version_Read(void)
{
    Serial.write(packet_header);
    Serial.write(0x0A);
    Serial.write(CMD_version_read);
    Serial.write(model_Bolide);                 //Model
    Serial.write(type_Y01);                     //Type
    Serial.write(application_default);          //Application
    Serial.write(main_version_number);          //Main Version
    Serial.write(secondary_version_number);     //Secondary Version
    Serial.write(revision_number);              //Revision
    Serial.write(packet_tail);
}


void Packet_Error_Feedback(unsigned char CMD_reaction)
{
    Serial.write(packet_header);
    Serial.write(0x04);
    Serial.write(CMD_reaction);
    Serial.write(packet_tail);
}


//Motion Editor Task
void MotionEditor::packetTask()
{
    static int pBuffer[128] = {0};
    static unsigned char pIndex = 0, pLength = 0xFF, pCMD = 0x00;
    static unsigned char motor_ID = 0;
    static int position_ID = 0;
    static int seq_pPoseCnt = 0xFF, PoseCnt = 0;
    static int SeqCnt = 0;
    static int SeqProcessCnt = 0;
    static int _temp;

    _temp = Serial.read();
    if (_temp == packet_header)
    {
        goto _packet_start;
    }
    else
    {
        return;
    }
    _packet_start:
    pBuffer[header_address] = _temp;
    pIndex = 1;
    _reset_timer4(timeout_limit);
    packet_timeout_status = false;
    while ((_temp = Serial.read()) == -1)
    {
        if (packet_timeout_status)
        {
            Packet_Error_Feedback(0x00);
            return;
        }
    }
    pBuffer[length_address] = _temp;
    pLength = _temp;
    pIndex++;
    _reset_timer4(timeout_limit);
    packet_timeout_status = false;
    while ((_temp = Serial.read()) == -1)
    {
        if (packet_timeout_status)
        {
            Packet_Error_Feedback(0x00);
            return;
        }
    }
    pBuffer[CMD_address] = _temp;
    pCMD = _temp;
    pIndex++;
    _reset_timer4(timeout_limit);
    packet_timeout_status = false;
    while (1)
    {
        while ((_temp = Serial.read()) == -1)
        {
            if (packet_timeout_status)
            {
                Packet_Error_Feedback(0x00);
                return;
            }
        }
        pBuffer[pIndex] = _temp;
        pIndex++;
        _reset_timer4(timeout_limit);
        packet_timeout_status = false;
        if (pIndex == pLength)
        {
            cb_USB();
            _reset_timer4(timeout_limit);
            goto _packet_finish;
        }
    }
    _packet_finish:
    if (pBuffer[pIndex - 1] == packet_tail)
    {
        if (pCMD == CMD_init_motor)
        {//initial motion editor setting
            seq_trigger = false;
            SeqPos = 0;
            int poseSize = pBuffer[motor_num_address];

            XYZrobot.poseSize(poseSize);
            XYZrobot.readPose();
            Packet_Init(poseSize);
        }
        else if (pCMD == CMD_set_motor)
        {//set motor position
            seq_trigger = false;
            SeqPos = 0;
            motor_ID = pBuffer[motor_ID_address];
            position_ID = (pBuffer[motor_pos_msb] << 8) + pBuffer[motor_pos_lsb];
            SetPositionI_JOG(motor_ID, 0x00, position_ID);
            Packet_Set(motor_ID, position_ID);
        }
        else if (pCMD == CMD_capture_motor)
        {//get motor position
            seq_trigger = false;
            SeqPos = 0;
            motor_ID = pBuffer[motor_ID_address];
            Packet_Capture(motor_ID);
        }
        else if (pCMD == CMD_relax_motor)
        {//relax motor
            seq_trigger = false;
            SeqPos = 0;
            motor_ID = pBuffer[motor_ID_address];
            A1_16_TorqueOff(motor_ID);
            Packet_Relax(motor_ID);
        }
        else if (pCMD == CMD_SN_read)
        {                  // serial number read
            seq_trigger = false;
            SeqPos = 0;
            Packet_SN();
        }
        else if (pCMD == CMD_SEQ_load_PoseCnt)
        {//load total pose number
            seq_trigger = false;
            SeqPos = 0;
            seq_pPoseCnt = pBuffer[seq_pose_cnt_address];
            if (seq_pPoseCnt > max_pose_index)
            {
                Packet_Error_Feedback(0x00);
            }
            else
            {
                Packet_Error_Feedback(0x01);
                SeqProcessCnt = SEQ_Process_load_PoseCnt;
                seq_loop_trigger = false;
            }
        }
        else if (pCMD == CMD_SEQ_loop_load_PoseCnt)
        {//load loop sequence pose number
            seq_trigger = false;
            SeqPos = 0;
            seq_pPoseCnt = pBuffer[seq_pose_cnt_address];
            if (seq_pPoseCnt > max_pose_index)
            {
                Packet_Error_Feedback(0x00);
            }
            else
            {
                Packet_Error_Feedback(0x01);
                SeqProcessCnt = SEQ_Process_load_PoseCnt;
                seq_loop_trigger = true;
            }
        }
        else if (pCMD == CMD_SEQ_load_Pose)
        {//load pose in sequence
            static int PoseID = 0, _i = 0;
            seq_trigger = false;
            SeqPos = 0;
            if (SeqProcessCnt == SEQ_Process_load_PoseCnt)
            {
                PoseID = pBuffer[seq_pose_ID_address];
                for (_i = 0; _i < XYZrobot.poseSize(); _i++)
                {
                    poses[PoseCnt][_i] = (pBuffer[seq_pose_start_address + 2 * _i] << 8) +
                                         pBuffer[seq_pose_start_address + 1 + 2 * _i];
                    pose_index[PoseCnt] = PoseID;
                }
                PoseCnt++;
                if (PoseCnt == seq_pPoseCnt)
                {
                    Packet_Error_Feedback(0x02);
                    PoseCnt = 0;
                    SeqProcessCnt = SEQ_Process_load_Pose;
                }
                else
                {
                    Packet_Error_Feedback(0x01);
                }
            }
            else
            {
                Packet_Error_Feedback(0x00);
            }
        }
        else if (pCMD == CMD_SEQ_load_SEQCnt)
        {//load total sequence number
            seq_trigger = false;
            SeqPos = 0;
            if (SeqProcessCnt == SEQ_Process_load_Pose)
            {
                seq_pSeqCnt = pBuffer[seq_seq_cnt_address];
                if (seq_pSeqCnt > max_seq_index)
                {
                    Packet_Error_Feedback(0x00);
                }
                else
                {
                    Packet_Error_Feedback(0x01);
                    SeqProcessCnt = SEQ_Process_load_SEQCnt;
                }
            }
            else
            {
                Packet_Error_Feedback(0x00);
            }
        }
        else if (pCMD == CMD_SEQ_load_SEQ)
        {//load sequence
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
                    Packet_Error_Feedback(0x02);
                    SeqCnt = 0;
                    seq_trigger = true;
                    XYZrobot.readPose();
                    SeqProcessCnt = SEQ_Process_load_SEQ;
                }
                else
                {
                    Packet_Error_Feedback(0x01);
                }
            }
            else
            {
                Packet_Error_Feedback(0x00);
            }
        }
        else if (pCMD == CMD_SEQ_halt)
        {//halt sequence
            seq_trigger = false;
            //halt sequence
        }
        else if (pCMD == CMD_SEQ_relax)
        {//relax servo
            seq_trigger = false;
            A1_16_TorqueOff(A1_16_Broadcast_ID);
        }
        else if (pCMD == CMD_version_read)
        {
            seq_trigger = false;
            SeqPos = 0;
            Packet_Version_Read();
        }
    }
    else
    {
        Packet_Error_Feedback(0x00);
        pLength = 0xFF;
    }
}


void MotionEditor::seqPlay()
{
    static int _i = 0;
    static int pose_index = 0;
    pose_index = sequence[SeqPos].pose;
    for (_i = 0; _i < XYZrobot.poseSize(); _i++)
    {
        XYZrobot.setNextPose(_i + 1, poses[pose_index][_i]);
    }
    XYZrobot.interpolateSetup(sequence[SeqPos].time);
    while (XYZrobot.interpolating())
    {
        XYZrobot.interpolateStep();
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
