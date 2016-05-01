//
// Created by Anton Matosov on 4/30/16.
//

#pragma once 

#import "ActionsEngineProtocol.h"

class ActionsEngine : public ActionsEngineProtocol
{
public:

    virtual void performAction(int actionID);
};


