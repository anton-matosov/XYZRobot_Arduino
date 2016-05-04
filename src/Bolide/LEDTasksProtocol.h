#pragma once

class LEDTasksProtocol
{
public:
    virtual void switchToMode(char mode) = 0;
    virtual char currentMode() const = 0;
    virtual void onTimer() = 0;

    virtual ~LEDTasksProtocol() {}
};


