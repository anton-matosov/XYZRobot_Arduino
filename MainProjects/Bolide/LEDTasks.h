//
// Created by Anton Matosov on 4/30/16.
//

#pragma once

#include "LEDTasksProtocol.h"

class LEDTasks : public LEDTasksProtocol
{
public:

    virtual void runTask(int id);
};


