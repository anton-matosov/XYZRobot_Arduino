//
// Created by Anton Matosov on 4/30/16.
//

#pragma once 

#include "ActionsEngineProtocol.h"

class ActionsEngine : public ActionsEngineProtocol
{
public:

    virtual void perform(int actionID);
};


