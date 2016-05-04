//
// Created by Anton Matosov on 4/30/16.
//

#include <USBAPI.h>
#include "LEDTasks.h"
#include "Y-01_Board.h"

//=== LED Frequency ===
const PROGMEM uint16_t log_light_40[41] = {1,
                                           1, 1, 2, 2, 2, 3, 3, 4, 5, 6,
                                           7, 8, 10, 11, 13, 16, 19, 23, 27, 32,
                                           38, 45, 54, 64, 76, 90, 108, 128, 152, 181,
                                           215, 256, 304, 362, 430, 512, 608, 723, 860, 1023};

void LEDTasks::switchToMode(char mode)
{
    if (mode != 0)
    {
        TCNT3 = (uint16_t)-1;
        _enable_timer3();
        _mode = mode;
    }
    else
    {
        EYE_LED_OFF;
        _disable_timer3();
        _mode = 0;
    }
}

char LEDTasks::currentMode() const
{
    return _mode;
}

void LEDTasks::onTimer()
{
    if (_mode == 1)
    {
        if (blink_LED)
        {
            EYE_LED_BLE;
        }
        else
        {
            EYE_LED_GRN;
        }
        blink_LED = !blink_LED;
        _reset_timer3(4500);
    }
    else if (_mode == 2)
    {
        if (R < 40)
        {
            R++;
            OCR5A = pgm_read_word_near(&log_light_40[R]);
        }
        else if (_R > 0)
        {
            _R--;
            OCR5A = pgm_read_word_near(&log_light_40[_R]);
        }
        else if (G < 40)
        {
            G++;
            OCR5B = pgm_read_word_near(&log_light_40[G]);
            EYE_LED_BLE;
        }
        else if (_G > 0)
        {
            _G--;
            OCR5B = pgm_read_word_near(&log_light_40[_G]);
        }
        else if (B < 40)
        {
            B++;
            OCR5C = pgm_read_word_near(&log_light_40[B]);
            EYE_LED_GRN;
        }
        else if (_B > 0)
        {
            _B--;
            OCR5C = pgm_read_word_near(&log_light_40[_B]);
        }
        else
        {
            R = 0;
            G = 0;
            B = 0;
            _R = 41;
            _G = 41;
            _B = 41;
        }
        _reset_timer3(200);
    }
    else if (_mode == 3)
    {
        if (R < 40)
        {
            R++;
            OCR5A = pgm_read_word_near(&log_light_40[R]);
        }
        else if (_R > 0)
        {
            _R--;
            OCR5A = pgm_read_word_near(&log_light_40[_R]);
        }
        else if (G < 40)
        {
            G++;
            OCR5B = pgm_read_word_near(&log_light_40[G]);
        }
        else if (_G > 0)
        {
            _G--;
            OCR5B = pgm_read_word_near(&log_light_40[_G]);
        }
        else if (B < 40)
        {
            B++;
            OCR5C = pgm_read_word_near(&log_light_40[B]);
        }
        else if (_B > 0)
        {
            _B--;
            OCR5C = pgm_read_word_near(&log_light_40[_B]);
        }
        else
        {
            R = 0;
            G = 0;
            B = 0;
            _R = 41;
            _G = 41;
            _B = 41;
        }
        _reset_timer3(200);
    }
}