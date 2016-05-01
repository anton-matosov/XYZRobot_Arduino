//
// Created by Anton Matosov on 4/30/16.
//

#include <USBAPI.h>
#include "OnBoardButtons.h"
#include "Robot.h"

//Digital input Pin
#define BUTTON1_PIN             32
#define BUTTON2_PIN             33
#define BUTTON3_PIN             34
#define BUTTON4_PIN             35

//Button
#define KEY_MASK_BUTTON_1            0x01
#define KEY_MASK_BUTTON_2            0x02
#define KEY_MASK_BUTTON_3            0x04
#define KEY_MASK_BUTTON_4            0x08

// Button function
void OnBoardButtons::checkButtonStates()
{
    static unsigned char buttonTimer = 0x00;
    static int lastKeyMaskPressed = 0x00;
    int keyMask = !digitalRead(BUTTON1_PIN)
                  | ((!digitalRead(BUTTON2_PIN)) << 1)
                  | ((!digitalRead(BUTTON3_PIN)) << 2)
                  | ((!digitalRead(BUTTON4_PIN)) << 3);

    if (keyMask != lastKeyMaskPressed)
    {
        buttonTimer++;
    }
    else
    {
        buttonTimer = 0;
    }

    if (buttonTimer > 20)
    {
        buttonTimer = 0;
        lastKeyMaskPressed = keyMask;
        if (keyMask != 0)
        {
            LED_Task(2);
            if (keyMask == KEY_MASK_BUTTON_1)
            {
                Robot::sharedInstance().actionsEngine().performAction(RB_1);
            }
            else if (keyMask == KEY_MASK_BUTTON_2)
            {
                Robot::sharedInstance().actionsEngine().performAction(RB_2);
            }
            else if (keyMask == KEY_MASK_BUTTON_3)
            {
                Robot::sharedInstance().actionsEngine().performAction(RB_3);
            }
            else if (keyMask == KEY_MASK_BUTTON_4)
            {
                Robot::sharedInstance().actionsEngine().performAction(RB_4);
            }
            LED_Task(0);
        }
    }
}