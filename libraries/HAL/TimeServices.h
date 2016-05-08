#pragma once 

namespace HAL
{
class TimeServices
{
public:
    virtual unsigned long milliseconds() = 0;
    virtual unsigned long microseconds() = 0;

    virtual ~TimeServices()
    { }
};
}


