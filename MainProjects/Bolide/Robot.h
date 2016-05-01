//
// Created by Anton Matosov on 4/30/16.
//

#pragma once 

#include "ActionsEngine.h"
#include "LEDTasks.h"

class Robot
{
public:
    static Robot& sharedInstance();

    LEDTasksProtocol& LEDTasks();

    ActionsEngineProtocol& actionsEngine();

private:
    ActionsEngine _actionsEngine;
    LEDTasks _ledTasks;
};


