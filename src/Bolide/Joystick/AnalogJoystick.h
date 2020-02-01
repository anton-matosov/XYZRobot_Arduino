//
// Created by Anton Matosov on 4/25/16.
//

#pragma once


class AnalogJoystick
{
public:
    AnalogJoystick();
    explicit AnalogJoystick(int *joystick);

    void update(int *joystick);

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
