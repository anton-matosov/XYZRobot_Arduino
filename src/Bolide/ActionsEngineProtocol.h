//
// Created by Anton Matosov on 4/30/16.
//

#pragma once 

class ActionsEngineProtocol
{
public:
    virtual void perform(int actionID) = 0;

    virtual ~ActionsEngineProtocol() {}
};