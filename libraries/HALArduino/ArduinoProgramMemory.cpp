//
// Created by Anton Matosov on 5/5/16.
//

#include <cstddef>
#include <Arduino.h>
#include "ArduinoProgramMemory.h"

uint8_t ArduinoProgramMemory::readByteNear(const void* addr)
{
    return pgm_read_byte_near(addr);
}

uint16_t ArduinoProgramMemory::readWordNear(const void* addr)
{
    return pgm_read_word_near(addr);
}

uint32_t ArduinoProgramMemory::readDwordNear(const void* addr)
{
    return pgm_read_dword_near(addr);
}

float ArduinoProgramMemory::readFloatNear(const void* addr)
{
    return pgm_read_float_near(addr);
}

void* ArduinoProgramMemory::readPtrNear(const void* addr)
{
    return pgm_read_ptr_near(addr);
}



