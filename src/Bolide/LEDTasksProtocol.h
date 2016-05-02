#pragma once

class LEDTasksProtocol
{
public:
    virtual void runTask(char id) = 0;
    virtual ~LEDTasksProtocol() {}
};


