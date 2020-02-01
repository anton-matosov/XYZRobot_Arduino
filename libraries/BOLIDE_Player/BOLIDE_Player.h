/*
  BOLIDE_Player.h - Modified for XYZrobot ATmega 1280 control board.
  Copyright (c) 2015 Wei-Shun You. XYZprinting Inc.  All right reserved.
*/
/*
  BioloidController.h - ArbotiX Library for Bioloid Pose Engine
  Copyright (c) 2008-2012 Michael E. Ferguson.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef BOLIDE_Player_h
#define BOLIDE_Player_h

/* poses:
 *  PROGMEM prog_uint16_t name[ ] = {4,512,512,482,542}; // first number is # of servos
 * sequences:
 *  PROGMEM transition_t name[] = {{NULL,count},{pose_name,1000},...} 
 */

#include "A1-16.h"

class ProgramMemoryProtocol;
class SerialProtocol;

namespace HAL
{
class TimeServices;
}

/* pose engine runs at 30Hz (33ms between frames) 
   recommended values for interpolateSetup are of the form X*BIOLOID_FRAME_LENGTH - 1 */
#define A1_16_FRAME_LENGTH      33
/* we need some extra resolution, use 13 bits, rather than 10, during interpolation */
#define A1_16_SHIFT             6

/** a structure to hold transitions **/
typedef struct
{
    const uint16_t *pose;    // addr of pose to transition to
    int time;               // time for transition
} transition_t;

typedef struct
{
    void *unused;
    int totalPoses; // number of transitions in the play sequence
} TransitionConfig;

/** Bioloid Controller Class for mega324p/644p clients. **/
class BOLIDE_Player
{
public:
    /* New-style constructor/setup */
    void setup(unsigned long baud, uint8_t servo_cnt,
               ProgramMemoryProtocol& programMemory,
               SerialProtocol& serialChannel,
               HAL::TimeServices& timeServices);        // baud usually 115200

    void torqueOff();

    /* Pose Manipulation */
    void loadPose(const unsigned int *poseAddress); // load a named pose from FLASH
    void readPose();                            // read a pose in from the servos  
    void writePose();                           // write a pose out to the servos
    int getCurPose(int id);                     // get a servo value in the current pose
    int getNextPose(int id);                    // get a servo value in the next pose
    void setNextPose(int id, int pos);          // set a servo value in the next pose
    void setId(uint8_t index, uint8_t id);              // set the id of a particular storage index
    uint8_t getId(uint8_t index);                       // get the id of a particular storage index

    /* Pose Engine */
    void interpolateSetup(unsigned int time);            // calculate speeds for smooth transition
    void interpolateStep();                     // move forward one step in current interpolation

    /* to interpolate:
     *  bioloid.loadPose(myPose);
     *  bioloid.interpolateSetup(67);
     *  while(bioloid._interpolating > 0){
     *      bioloid.interpolateStep();
     *      delay(1);
     *  }
     */

    /* Sequence Engine */
    void playSeq(const transition_t *addr);  // load a sequence and play it from FLASH
    void play();                                // keep moving forward in time

    /* to run the sequence engine:
     *  bioloid.playSeq(walk);
     *  while(bioloid._playing){
     *      bioloid.play();
     *  }
     */

    void printPose();

    // Exposing internals for no good reason
    uint8_t poseSize();
    void poseSize(uint8_t newSize);
    bool interpolating();
    bool playing();
private:
    bool _playing;                      // are we _playing a sequence? 0=No, 1=Yes
    unsigned char _interpolating;                // are we in an interpolation? 0=No, 1=Yes
    uint8_t _poseSize;                               // how many servos are in this pose, used by Sync()


    uint16_t *pose_;                       // the current pose, updated by Step(), set out by Sync()
    uint16_t *nextpose_;                   // the destination pose, where we put on load
    int *speed_;                               // speeds for interpolation
    uint8_t *id_;                        // servo id for this index

    unsigned long lastframe_;                   // time last frame was sent out
    unsigned int total_frame;                    // Wei-Shun You edits: total frame between two pose
    unsigned int frame_counter;                // Wei-Shun You edits: record how many frames runs

    transition_t *sequence;                    // sequence we are running
    int transitions;                            // how many transitions we have left to load

    bool torqueOff_;
    bool recoveringTorque_;
    bool traceSeqPlay_;

    SerialProtocol* _serialChannel;
    ProgramMemoryProtocol* _programMemory;
    HAL::TimeServices* _timeServices;

    void printPose(uint16_t *poseToPrint, const char* label);
    void readPoseTo(uint16_t* saveToPose);
    void readPoseTo(uint16_t* saveToPose, unsigned char addr);
    void readPosGoalTo(uint16_t* saveToPose);
};

#endif
