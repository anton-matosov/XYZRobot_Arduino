//
// Created by Anton Matosov on 4/30/16.
//

#include "ActionsEngine.h"

extern void Action(int N);

void ActionsEngine::perform(int actionID)
{
    Action(actionID);
}

