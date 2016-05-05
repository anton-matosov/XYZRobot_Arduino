//
// Created by Anton Matosov on 4/30/16.
//

#pragma once

#include "LEDTasksProtocol.h"

class LEDTasks : public LEDTasksProtocol
{
public:
    void switchToMode(char mode) override;
    char currentMode() const override;
    void onTimer() override;

private:
    char _mode = 0;
    int R = 0, G = 0, B = 0;
    int _R = 41, _G = 41, _B = 41;
    bool blink_LED = true;
};


