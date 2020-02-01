//
// Created by Anton Matosov on 5/4/16.
//

#pragma once 

#include <HAL.h>

class HardwareSerial;

class ArduinoHardwareSerial : public SerialProtocol
{
public:
    ArduinoHardwareSerial(HardwareSerial& arduinoSerial, uint8_t rxdPin);

    void begin(const unsigned long baudRate, const uint8_t transferConfig = SERIAL_8N1) override;
    unsigned int write(uint8_t byte) override;
    bool available() override;
    uint8_t peek() override;
    uint8_t read() override;

private:
    HardwareSerial& _arduinoSerial;
    int8_t _rxdPin;
};


