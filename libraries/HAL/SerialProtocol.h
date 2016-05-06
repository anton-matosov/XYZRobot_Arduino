#pragma once 

class SerialProtocol
{
public:
    virtual void begin(const unsigned long baudRate, const uint8_t transferConfig) = 0;
    virtual size_t write(uint8_t byte) = 0;

    virtual int available() = 0;
    virtual int peek() = 0;
    virtual int read() = 0;

    virtual ~SerialProtocol()
    { }
};


