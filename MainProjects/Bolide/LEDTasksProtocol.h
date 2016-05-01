#pragma once

class LEDTasksProtocol
{
public:
    virtual void runTask(int id) = 0;
    virtual ~LEDTasksProtocol() {}
};


