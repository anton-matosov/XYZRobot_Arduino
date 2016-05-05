//
// Created by Anton Matosov on 4/30/16.
//

#include <USBAPI.h>
#include "OnBoardButtons.h"
#include "Robot.h"
#include "ScopedLEDTask.h"


//=== Robot Button Actions ====
#define RB_1  23
#define RB_2  24
#define RB_3  25
#define RB_4  26


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

//Configure onboard button pin
void OnBoardButtons::setup()
{
    pinMode(BUTTON1_PIN, INPUT);
    pinMode(BUTTON2_PIN, INPUT);
    pinMode(BUTTON3_PIN, INPUT);
    pinMode(BUTTON4_PIN, INPUT);
}


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
            ScopedLEDTask ledTask(2, Robot::sharedInstance().LED());

            if (keyMask == KEY_MASK_BUTTON_1)
            {
                Robot::sharedInstance().actionsEngine().perform(RB_1);
            }
            else if (keyMask == KEY_MASK_BUTTON_2)
            {
                Robot::sharedInstance().actionsEngine().perform(RB_2);
            }
            else if (keyMask == KEY_MASK_BUTTON_3)
            {
                Robot::sharedInstance().actionsEngine().perform(RB_3);
            }
            else if (keyMask == KEY_MASK_BUTTON_4)
            {
                Robot::sharedInstance().actionsEngine().perform(RB_4);
            }
        }
    }
}