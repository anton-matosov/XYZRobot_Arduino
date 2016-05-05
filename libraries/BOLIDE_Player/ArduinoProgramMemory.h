//
// Created by Anton Matosov on 5/5/16.
//

#pragma once 

#include <stdint-gcc.h>
#include "ProgramMemoryProtocol.h"

class ArduinoProgramMemory : public ProgramMemoryProtocol
{
public:
    uint8_t readByteNear(void* addr) override;
    uint16_t readWordNear(void* addr) override;
    uint32_t readDwordNear(void* addr) override;
    float readFloatNear(void* addr) override;
    void* readPtrNear(void* addr) override;
};


