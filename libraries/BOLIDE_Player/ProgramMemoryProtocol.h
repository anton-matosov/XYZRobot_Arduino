#pragma once 

class ProgramMemoryProtocol
{
public:
    virtual uint8_t readByteNear(void *addr) = 0;
    virtual uint16_t readWordNear(void *addr) = 0;
    virtual uint32_t readDwordNear(void *addr) = 0;
    virtual float readFloatNear(void *addr) = 0;
    virtual void* readPtrNear(void *addr) = 0;

    virtual ~ProgramMemoryProtocol()
    { }
};


