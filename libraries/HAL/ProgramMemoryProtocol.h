#pragma once 

#include <stdint.h>

class ProgramMemoryProtocol
{
public:
    virtual uint8_t readByteNear(const void *addr) = 0;
    virtual uint16_t readWordNear(const void *addr) = 0;
    virtual uint32_t readDwordNear(const void *addr) = 0;
    virtual float readFloatNear(const void *addr) = 0;
    virtual void* readPtrNear(const void *addr) = 0;

    virtual ~ProgramMemoryProtocol()
    { }
};


