//
// Created by Anton Matosov on 5/4/16.
//

#pragma once 

#include <stdint.h>
#import "../HAL/SerialProtocol.h"

class HardwareSerial;

class ArduinoHardwareSerial : public SerialProtocol
{
public:
    ArduinoHardwareSerial(HardwareSerial& arduinoSerial);

    void begin(const unsigned long baudRate, const uint8_t transferConfig) override;
    unsigned int write(uint8_t byte) override;
    int available() override;
    int peek() override;
    int read() override;

private:
    HardwareSerial& _arduinoSerial;
};


