//
// Created by Anton Matosov on 4/30/16.
//

#include "Robot.h"

Robot& Robot::sharedInstance()
{
    static Robot robot;
    return robot;
}

ActionsEngineProtocol& Robot::actionsEngine()
{
    return _actionsEngine;
}

LEDTasksProtocol& Robot::LED()
{
    return _ledTasks;
}





