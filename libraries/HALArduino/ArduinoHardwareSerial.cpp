//
// Created by Anton Matosov on 5/4/16.
//

#include <HardwareSerial.h>
#include "ArduinoHardwareSerial.h"

ArduinoHardwareSerial::ArduinoHardwareSerial(HardwareSerial& arduinoSerial, uint8_t rxdPin)
    : _arduinoSerial(arduinoSerial)
      , _rxdPin(rxdPin)
{
}

void ArduinoHardwareSerial::begin(const unsigned long baudRate, const uint8_t transferConfig)
{
    DDRD &= ~_BV(_rxdPin);            //set the RXD input
    PORTD |= _BV(_rxdPin);        //pull-high the RXD pinout

    _arduinoSerial.begin(baudRate, transferConfig);
}

unsigned int ArduinoHardwareSerial::write(uint8_t byte)
{
    return _arduinoSerial.write(byte);
}

bool ArduinoHardwareSerial::available()
{
    return _arduinoSerial.available() != 0;
}

uint8_t ArduinoHardwareSerial::peek()
{
    return static_cast<uint8_t>(_arduinoSerial.peek());
}

uint8_t ArduinoHardwareSerial::read()
{
    return static_cast<uint8_t>(_arduinoSerial.read());
}

