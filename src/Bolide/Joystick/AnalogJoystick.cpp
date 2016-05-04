//
// Created by Anton Matosov on 4/25/16.
//

#include <stdlib.h>
#include "AnalogJoystick.h"

enum JoystickOffsets
{
    kJoyOffsetRested = 125,
    kJoyOffsetThreshold = 20,
};

AnalogJoystick::AnalogJoystick()
    : horizontal_(kJoyOffsetRested)
      , vertical_(kJoyOffsetRested)
{
}

AnalogJoystick::AnalogJoystick(int *joystick)
    : horizontal_(joystick[0])
      , vertical_(joystick[1])
{
}

void AnalogJoystick::update(int *joystick)
{
    horizontal_ = joystick[0];
    vertical_ = joystick[1];
}

bool AnalogJoystick::isRested()
{
    return isAxisRested(horizontal_) && isAxisRested(vertical_);
}

bool AnalogJoystick::isAxisRested(const int joystickAxis)
{
    return abs(joystickAxis - kJoyOffsetRested) < kJoyOffsetThreshold;
}

bool AnalogJoystick::isRight()
{
    const int horizontalOffset = horizontal_ - kJoyOffsetRested;
    const int absoluteHorizontalOffset = abs(horizontalOffset);
    const int absoluteVerticalOffset = abs(vertical_ - kJoyOffsetRested);

    return horizontalOffset > 0 &&
           absoluteHorizontalOffset > kJoyOffsetThreshold &&
           absoluteHorizontalOffset > absoluteVerticalOffset;
}

bool AnalogJoystick::isLeft()
{
    const int horizontalOffset = horizontal_ - kJoyOffsetRested;
    const int absoluteHorizontalOffset = abs(horizontalOffset);
    const int absoluteVerticalOffset = abs(vertical_ - kJoyOffsetRested);

    return horizontalOffset < 0 &&
           absoluteHorizontalOffset > kJoyOffsetThreshold &&
           absoluteHorizontalOffset > absoluteVerticalOffset;
}

bool AnalogJoystick::isUp()
{
    const int verticalOffset = vertical_ - kJoyOffsetRested;
    const int absoluteHorizontalOffset = abs(horizontal_ - kJoyOffsetRested);
    const int absoluteVerticalOffset = abs(verticalOffset);

    return verticalOffset > 0 &&
           absoluteVerticalOffset > kJoyOffsetThreshold &&
           absoluteVerticalOffset > absoluteHorizontalOffset;
}

bool AnalogJoystick::isDown()
{
    const int verticalOffset = vertical_ - kJoyOffsetRested;
    const int absoluteHorizontalOffset = abs(horizontal_ - kJoyOffsetRested);
    const int absoluteVerticalOffset = abs(verticalOffset);

    return verticalOffset < 0 &&
           absoluteVerticalOffset > kJoyOffsetThreshold &&
           absoluteVerticalOffset > absoluteHorizontalOffset;
}