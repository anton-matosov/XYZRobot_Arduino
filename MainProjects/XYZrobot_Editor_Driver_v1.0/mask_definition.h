#ifndef MASK_DEFINITION_H
#define MASK_DEFINITION_H

#define max_pose_index             50
#define max_seq_index              100

#define _enable_timer4() TIMSK4 |= _BV(TOIE4)
#define _disable_timer4() TIMSK4 &= ~_BV(TOIE4)
#define timeout_limit -15625    // Ticks for 1 sec @16 MHz,prescale=1024
#define _reset_timer4() TCNT4 = timeout_limit
#define _reset_timer_counter() timeout_counter = 0

#define packet_header              0xFF
#define packet_tail                0xFE

#define header_address             0x00
#define length_address             0x01
#define CMD_address                0x02
#define motor_ID_address           0x03

#define motor_num_address          0x03
#define motor_pos_msb              0x04
#define motor_pos_lsb              0x05

#define CMD_init_motor             0x01
#define CMD_set_motor              0x02
#define CMD_capture_motor          0x03
#define CMD_relax_motor            0x04

#define CMD_SEQ_load_PoseCnt       0x10
#define CMD_SEQ_load_Pose          0x11
#define CMD_SEQ_load_SEQCnt        0x12
#define CMD_SEQ_load_SEQ           0x13
#define CMD_SEQ_loop_load_PoseCnt  0x14
#define CMD_SEQ_relax              0x20
#define CMD_SEQ_halt               0x30

#define SEQ_Process_load_PoseCnt   0x01
#define SEQ_Process_load_Pose      0x02
#define SEQ_Process_load_SEQCnt    0x03
#define SEQ_Process_load_SEQ       0x04

#define seq_pose_cnt_address       0x03
#define seq_pose_ID_address        0x03
#define seq_seq_cnt_address        0x03
#define seq_pose_start_address     0x04
#define seq_pose_name_address      0x03
#define seq_pose_time_MSB_address  0x04
#define seq_pose_time_LSB_address  0x05

#define CMD_packet_error           0xFD
#define packet_timeout             0x01
#define packet_error               0x02

#endif
