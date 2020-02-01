//
// Created by Anton Matosov on 5/8/16.
//

#include <Arduino.h>
#include "ArduinoTimeServices.h"


unsigned long HALArduino::ArduinoTimeServices::milliseconds()
{
    return millis();
}

unsigned long HALArduino::ArduinoTimeServices::microseconds()
{
    return micros();
}



