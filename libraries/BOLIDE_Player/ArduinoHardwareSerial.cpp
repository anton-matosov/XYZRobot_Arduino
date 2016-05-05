//
// Created by Anton Matosov on 5/4/16.
//

#include <HardwareSerial.h>
#include "ArduinoHardwareSerial.h"

ArduinoHardwareSerial::ArduinoHardwareSerial(HardwareSerial& arduinoSerial)
    : _arduinoSerial(arduinoSerial)
{
}

void ArduinoHardwareSerial::begin(const unsigned long baudRate, const uint8_t transferConfig)
{
    _arduinoSerial.begin(baudRate, transferConfig);
}

unsigned int ArduinoHardwareSerial::write(uint8_t byte)
{
    return _arduinoSerial.write(byte);
}

int ArduinoHardwareSerial::available()
{
    return _arduinoSerial.available();
}

int ArduinoHardwareSerial::peek()
{
    return _arduinoSerial.peek();
}

int ArduinoHardwareSerial::read()
{
    return _arduinoSerial.read();
}

