//
// Created by Anton Matosov on 4/30/16.
//

#include "LEDTasks.h"

extern void LED_Task(char mode);

void LEDTasks::runTask(char id)
{
    LED_Task(id);
}

