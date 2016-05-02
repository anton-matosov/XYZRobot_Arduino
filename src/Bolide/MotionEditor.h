//
// Created by Anton Matosov on 4/30/16.
//

#pragma once

class MotionEditor
{
public:
    static bool seq_trigger;
    static bool packet_timeout_status;

    static void packetTask();
    static void seqPlay();
};
