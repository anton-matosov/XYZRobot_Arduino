#include <A1-16.h>
#include "Check_Mask.h"

#define ID_default 0x01
#define _enable_timer4() TIMSK4 |= _BV(TOIE4)
#define _disable_timer4() TIMSK4 &= ~_BV(TOIE4)
#define _reset_timer4() TCNT4 = -15625
#define _reset_timer_counter() timeout_counter = 0

static char status_check_1 = 0x00;
static char status_check_2 = 0x00;
static int timeout_counter = 0;

void setup()
{
    Serial.begin(115200);
    MOTOR_task_setup();
    TIMER4_task_setup();
}

void loop()
{
    static int ID_Setting;
    static int temp = 0;
_receive_Data:
    while (Serial.available() < 1)
    {
    }
    ID_Setting = Serial.parseInt();
    Serial.print("ID_setting : ");
    Serial.println(ID_Setting);
    while (Serial.read() != -1)
    {
    }
    status_check_1 = 0x00;
    status_check_2 = 0x00;
    temp = 0x00;
    _reset_timer_counter();
    _reset_timer4();
    _enable_timer4();
    if ((ID_Setting <= 0) || (ID_Setting >= 19))
    {
        status_check_2 |= Out_of_Range_mask;
        goto _finish_test;
    }
    WriteDataRAM1(A1_16_Broadcast_ID, RAM_LED_Control, LED_NO_MASK);
    delay(20);
    WriteDataRAM1(A1_16_Broadcast_ID, RAM_Alarm_LED_Policy, 0xFF);
    delay(20);
    WriteDataRAM1(A1_16_Broadcast_ID, RAM_LED_Control, LED_RED_MASK);
    delay(20);
    while (temp != ID_Setting)
    {
        SetID(A1_16_Broadcast_ID, ID_Setting);
        delay(20);
        temp = ReadDataEEP1(ID_Setting, EEP_sID);
        if ((status_check_2 & timeout_mask))
        {
            goto _Timeout_Feedback;
        }
    }
    status_check_1 |= ID_Setting_mask;
    while (abs(temp - 724) > error_range)
    {
        SetPositionI_JOG(ID_Setting, 0x00, 724);
        delay(500);
        temp = ReadPosition(ID_Setting);
        if ((status_check_2 & timeout_mask))
        {
            goto _Timeout_Feedback;
        }
    }
    while (abs(temp - 512) > error_range)
    {
        SetPositionI_JOG(ID_Setting, 0x00, 512);
        delay(500);
        temp = ReadPosition(ID_Setting);
        if ((status_check_2 & timeout_mask))
        {
            goto _Timeout_Feedback;
        }
    }
    while (abs(temp - 300) > error_range)
    {
        SetPositionI_JOG(ID_Setting, 0x00, 300);
        delay(500);
        temp = ReadPosition(ID_Setting);
        if ((status_check_2 & timeout_mask))
        {
            goto _Timeout_Feedback;
        }
    }
    while (abs(temp - 512) > error_range)
    {
        SetPositionI_JOG(ID_Setting, 0x00, 512);
        delay(500);
        temp = ReadPosition(ID_Setting);
        if ((status_check_2 & timeout_mask))
        {
            goto _Timeout_Feedback;
        }
    }
    status_check_1 |= Position_mask;
    WriteDataRAM1(ID_Setting, RAM_LED_Control, LED_GRN_MASK);
    delay(20);
_finish_test:
    _disable_timer4();
    _reset_timer_counter();
    status_check_2 |= timeout_mask;
    Serial.println("Setting ID Successful!!");
    goto _receive_Data;
_Timeout_Feedback:
    _disable_timer4();
    _reset_timer_counter();
    Serial.println("Setting ID Fail!!");
}

void MOTOR_task_setup(void)
{
    A1_16_Ini(115200);
}

//----------------------------------------------
void TIMER4_task_setup()
{
    TCCR4A = 0x00;              // Normal mode, just as a Timer
    TCCR4B |= _BV(CS32);          // prescaler = CPU clock/1024
    TCCR4B &= ~_BV(CS31);
    TCCR4B |= _BV(CS30);
    TCNT4 = -15625;
}

ISR(TIMER4_OVF_vect)
{
    timeout_counter++;
    if (timeout_counter > Timeout_Limit)
    {
        status_check_2 |= timeout_mask;
        _reset_timer_counter();
    }
    TCNT4 = -15625;               // Ticks for 1 second @16 MHz,prescale=1024
}
