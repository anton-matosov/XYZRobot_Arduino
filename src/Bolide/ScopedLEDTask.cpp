//
// Created by Anton Matosov on 5/4/16.
//

#include "ScopedLEDTask.h"
#include "LEDTasksProtocol.h"

ScopedLEDTask::ScopedLEDTask(char ledMode, LEDTasksProtocol& ledTasks)
    : _oldMode(ledTasks.currentMode())
    , _ledTasks(ledTasks)
{
    ledTasks.switchToMode(ledMode);
}

ScopedLEDTask::~ScopedLEDTask()
{
    _ledTasks.switchToMode(_oldMode);
}
