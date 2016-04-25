//
// Created by Anton Matosov on 4/25/16.
//

#pragma once

enum JoystickOffsets
{
    kJoyOffsetRested = 125,
    kJoyOffsetThreshold = 20,
};

class AnalogJoystick
{
public:
    AnalogJoystick(int *joystick)
        : horizontal_(joystick[0])
        , vertical_(joystick[1])
    {
    }

    bool isRested();

    bool isRight();
    bool isLeft();
    bool isUp();
    bool isDown();

private:
    bool isAxisRested(const int joystickAxis);

    int horizontal_;
    int vertical_;
};
