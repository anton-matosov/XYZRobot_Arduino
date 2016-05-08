//
// Created by Anton Matosov on 5/8/16.
//

#pragma once 

#import <HAL.h>

namespace HALArduino
{
class ArduinoTimeServices : public HAL::TimeServices
{
public:
    unsigned long milliseconds() override;
    unsigned long microseconds() override;
};
}

