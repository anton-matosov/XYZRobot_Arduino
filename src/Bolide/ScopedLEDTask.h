//
// Created by Anton Matosov on 5/4/16.
//

#pragma once 

class LEDTasksProtocol;

class ScopedLEDTask
{
public:
    ScopedLEDTask(char ledMode, LEDTasksProtocol& ledTasks);
    ~ScopedLEDTask();

private:
    char _oldMode;
    LEDTasksProtocol& _ledTasks;
};


