//
// Created by Anton Matosov on 5/5/16.
//

#pragma once 

#include <stdint.h>
#include <HAL.h>

class ArduinoProgramMemory : public ProgramMemoryProtocol
{
public:
    uint8_t readByteNear(const void* addr) override;
    uint16_t readWordNear(const void* addr) override;
    uint32_t readDwordNear(const void* addr) override;
    float readFloatNear(const void* addr) override;
    void* readPtrNear(const void* addr) override;
};


