#ifndef CRAWLER_USER_MOTION_H
#define CRAWLER_USER_MOTION_H

#include <avr/pgmspace.h>

#define Adjustment_index true
#define Avoidance_index false

//===== User Default Sequence ======
const PROGMEM uint16_t DefaultPose[] = {18, 367, 512, 512, 512, 512, 512, 657, 512, 512, 657, 512, 512, 512, 512, 512, 367, 512, 512};
const PROGMEM transition_t DefaultInitial[] = {{0,1} ,{DefaultPose,500}} ;
const PROGMEM uint16_t NonePose[] = {18, 367, 512, 512, 512, 512, 512, 657, 512, 512, 657, 512, 512, 512, 512, 512, 367, 512, 512};
const PROGMEM transition_t None[] = {{0,1} ,{DefaultPose,500}} ;
//=======================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================

//InitialPose
const PROGMEM uint16_t D_InitialPose[] = {18, 367, 512, 512, 512, 512, 512, 657, 512, 512, 657, 512, 512, 512, 512, 512, 367, 512, 512};

//Walkforward
const PROGMEM uint16_t D_WF_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_WF_2[] = {18, 288, 230, 420, 512, 408, 420, 492, 230, 420, 614, 616, 604, 594, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_WF_3[] = {18, 288, 408, 420, 512, 408, 420, 492, 408, 420, 614, 616, 604, 594, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_WF_4[] = {18, 410, 408, 420, 410, 230, 420, 614, 408, 420, 716, 793, 604, 472, 616, 604, 512, 793, 604};
const PROGMEM uint16_t D_WF_5[] = {18, 410, 408, 420, 410, 408, 420, 614, 408, 420, 716, 616, 604, 472, 616, 604, 512, 616, 604};

//Walkbackward
const PROGMEM uint16_t D_WB_1[] = {18, 350, 408, 420, 452, 408, 420, 584, 408, 420, 674, 616, 604, 572, 616, 604, 440, 616, 604};
const PROGMEM uint16_t D_WB_2[] = {18, 455, 230, 420, 452, 408, 420, 670, 230, 420, 674, 616, 604, 477, 793, 604, 440, 616, 604};
const PROGMEM uint16_t D_WB_3[] = {18, 455, 408, 420, 452, 408, 420, 670, 408, 420, 674, 616, 604, 477, 616, 604, 440, 616, 604};
const PROGMEM uint16_t D_WB_4[] = {18, 350, 408, 420, 552, 230, 420, 584, 408, 420, 574, 793, 604, 572, 616, 604, 360, 793, 604};
const PROGMEM uint16_t D_WB_5[] = {18, 350, 408, 420, 552, 408, 420, 584, 408, 420, 574, 616, 604, 572, 616, 604, 360, 616, 604};

//FastWalkforward
const PROGMEM uint16_t D_Fast_WF_1[] = {18, 411, 288, 291, 441, 290, 254, 513, 289, 284, 612, 736, 736, 582, 734, 770, 512, 735, 740};
const PROGMEM uint16_t D_Fast_WF_2[] = {18, 362, 250, 320, 442, 290, 290, 462, 250, 320, 612, 734, 734, 612, 774, 704, 512, 734, 734};
const PROGMEM uint16_t D_Fast_WF_3[] = {18, 362, 325, 373, 442, 290, 290, 462, 290, 290, 612, 734, 734, 612, 734, 734, 512, 734, 734};
const PROGMEM uint16_t D_Fast_WF_4[] = {18, 412, 290, 290, 412, 250, 320, 512, 290, 290, 662, 774, 704, 582, 734, 734, 562, 774, 704};
const PROGMEM uint16_t D_Fast_WF_5[] = {18, 412, 290, 290, 412, 290, 290, 512, 290, 290, 662, 699, 654, 582, 734, 734, 562, 734, 734};

//FastWalkbackward
const PROGMEM uint16_t D_Fast_WB_1[] = {18, 368, 285, 293, 447, 290, 390, 520, 282, 292, 657, 743, 733, 575, 737, 732, 507, 744, 731};
const PROGMEM uint16_t D_Fast_WB_2[] = {18, 432, 252, 318, 453, 278, 295, 592, 252, 319, 661, 743, 726, 512, 774, 705, 512, 742, 735};
const PROGMEM uint16_t D_Fast_WB_3[] = {18, 433, 283, 291, 458, 284, 294, 583, 282, 292, 659, 744, 725, 516, 737, 732, 505, 743, 723};
const PROGMEM uint16_t D_Fast_WB_4[] = {18, 375, 280, 297, 512, 254, 318, 525, 280, 288, 592, 769, 706, 603, 744, 729, 433, 769, 706};
const PROGMEM uint16_t D_Fast_WB_5[] = {18, 373, 279, 298, 512, 278, 302, 526, 279, 288, 593, 753, 717, 603, 745, 731, 433, 743, 721};

//Walkleftward
const PROGMEM uint16_t D_WL_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_WL_2[] = {18, 410, 230, 420, 512, 408, 420, 614, 230, 420, 614, 616, 604, 512, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_WL_3[] = {18, 410, 459, 574, 510, 470, 340, 613, 459, 574, 612, 565, 450, 510, 554, 684, 410, 565, 450};
const PROGMEM uint16_t D_WL_4[] = {18, 410, 408, 420, 512, 230, 420, 613, 408, 420, 614, 793, 604, 506, 616, 604, 409, 791, 604};

//Walkrightward
const PROGMEM uint16_t D_WR_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_WR_2[] = {18, 410, 408, 420, 512, 230, 420, 614, 408, 420, 614, 793, 604, 512, 616, 604, 410, 793, 604};
const PROGMEM uint16_t D_WR_3[] = {18, 410, 459, 574, 510, 470, 340, 614, 459, 574, 614, 565, 450, 512, 554, 684, 410, 565, 450};
const PROGMEM uint16_t D_WR_4[] = {18, 410, 230, 420, 512, 408, 420, 614, 230, 420, 614, 616, 604, 512, 793, 604, 410, 616, 604};

//FastTurnleft
const PROGMEM uint16_t D_Fast_TL_1[] = {18, 362, 290, 290, 452, 290, 290, 562, 290, 290, 662, 734, 734, 572, 734, 734, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TL_2[] = {18, 362, 290, 290, 522, 200, 320, 562, 287, 299, 712, 824, 704, 574, 733, 733, 552, 824, 704};
const PROGMEM uint16_t D_Fast_TL_3[] = {18, 362, 290, 290, 522, 290, 290, 562, 290, 290, 712, 734, 734, 574, 734, 734, 552, 734, 734};
const PROGMEM uint16_t D_Fast_TL_4[] = {18, 412, 200, 320, 452, 290, 290, 602, 200, 320, 662, 734, 734, 642, 824, 704, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TL_5[] = {18, 412, 290, 290, 452, 290, 290, 602, 290, 290, 662, 734, 734, 639, 734, 734, 462, 734, 734};

//FastTurnright
const PROGMEM uint16_t D_Fast_TR_1[] = {18, 362, 290, 290, 452, 290, 290, 562, 290, 290, 662, 734, 734, 572, 734, 734, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TR_2[] = {18, 312, 200, 320, 452, 290, 290, 522, 200, 320, 662, 734, 734, 502, 824, 704, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TR_3[] = {18, 312, 290, 290, 452, 290, 290, 522, 290, 290, 662, 734, 734, 502, 734, 734, 462, 734, 734};
const PROGMEM uint16_t D_Fast_TR_4[] = {18, 362, 290, 290, 382, 200, 320, 562, 290, 290, 612, 824, 704, 572, 734, 734, 352, 824, 704};
const PROGMEM uint16_t D_Fast_TR_5[] = {18, 362, 290, 290, 382, 290, 290, 562, 290, 290, 612, 734, 734, 572, 734, 734, 352, 734, 734};

//Turnleft
const PROGMEM uint16_t D_TL_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_TL_2[] = {18, 512, 230, 420, 512, 408, 420, 716, 230, 420, 614, 616, 604, 614, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_TL_3[] = {18, 512, 408, 420, 512, 408, 420, 716, 408, 420, 614, 616, 604, 614, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_TL_4[] = {18, 410, 408, 420, 614, 230, 420, 614, 408, 420, 716, 793, 604, 512, 616, 604, 512, 793, 604};
const PROGMEM uint16_t D_TL_5[] = {18, 410, 408, 420, 614, 408, 420, 614, 408, 420, 716, 616, 604, 512, 616, 604, 512, 616, 604};

//Turnright
const PROGMEM uint16_t D_TR_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_TR_2[] = {18, 410, 408, 420, 410, 230, 420, 614, 408, 420, 512, 793, 604, 512, 616, 604, 308, 793, 604};
const PROGMEM uint16_t D_TR_3[] = {18, 410, 408, 420, 410, 408, 420, 614, 408, 420, 512, 616, 604, 512, 616, 604, 308, 616, 604};
const PROGMEM uint16_t D_TR_4[] = {18, 308, 230, 420, 512, 408, 420, 512, 230, 420, 614, 616, 604, 410, 793, 604, 410, 616, 604};
const PROGMEM uint16_t D_TR_5[] = {18, 308, 408, 420, 512, 408, 420, 512, 408, 422, 614, 616, 604, 410, 616, 604, 410, 616, 604};

//InverseWalkforward
const PROGMEM uint16_t D_Inv_WF_1[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WF_2[] = {18, 308, 500, 900, 512, 350, 950, 512, 500, 900, 614, 674, 74, 614, 524, 124, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WF_3[] = {18, 308, 350, 950, 512, 350, 950, 512, 350, 950, 614, 674, 74, 614, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WF_4[] = {18, 410, 350, 950, 410, 500, 900, 614, 350, 950, 716, 524, 124, 512, 674, 74, 512, 524, 124};
const PROGMEM uint16_t D_Inv_WF_5[] = {18, 410, 350, 950, 410, 350, 950, 614, 350, 950, 716, 674, 74, 512, 674, 74, 512, 674, 74};

//InverseWalkbackward
const PROGMEM uint16_t D_Inv_WB_1[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WB_2[] = {18, 512, 500, 900, 512, 350, 950, 716, 500, 900, 614, 674, 74, 410, 524, 124, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WB_3[] = {18, 512, 350, 950, 512, 350, 950, 716, 350, 950, 614, 674, 74, 410, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WB_4[] = {18, 410, 350, 950, 614, 500, 900, 614, 350, 950, 512, 524, 124, 512, 674, 74, 308, 524, 124};
const PROGMEM uint16_t D_Inv_WB_5[] = {18, 410, 350, 950, 614, 350, 950, 614, 350, 950, 512, 674, 74, 512, 674, 74, 305, 674, 74};

//InverseWalkleftward
const PROGMEM uint16_t D_Inv_WL_1[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WL_2[] = {18, 410, 350, 950, 512, 500, 900, 614, 350, 950, 614, 524, 124, 512, 674, 74, 410, 524, 124};
const PROGMEM uint16_t D_Inv_WL_3[] = {18, 410, 296, 798, 512, 360, 1020, 614, 296, 798, 614, 728, 226, 512, 664, 4, 410, 728, 226};
const PROGMEM uint16_t D_Inv_WL_4[] = {18, 410, 500, 900, 512, 350, 950, 614, 500, 900, 614, 674, 74, 512, 524, 124, 410, 674, 74};

//InverseWalkrightward
const PROGMEM uint16_t D_Inv_WR_1[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WR_2[] = {18, 410, 500, 900, 512, 350, 950, 614, 500, 900, 614, 674, 74, 512, 524, 124, 410, 674, 74};
const PROGMEM uint16_t D_Inv_WR_3[] = {18, 410, 296, 798, 512, 360, 1020, 614, 296, 798, 614, 728, 226, 512, 664, 4, 410, 728, 226};
const PROGMEM uint16_t D_Inv_WR_4[] = {18, 410, 350, 950, 512, 500, 900, 614, 350, 950, 614, 524, 124, 512, 654, 74, 410, 524, 124};

//InverseTurnleft
const PROGMEM uint16_t D_Inv_TL_1[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_TL_2[] = {18, 410, 350, 950, 410, 500, 900, 614, 350, 950, 512, 524, 124, 512, 674, 74, 308, 524, 124};
const PROGMEM uint16_t D_Inv_TL_3[] = {18, 410, 350, 950, 410, 350, 950, 614, 350, 950, 512, 674, 74, 512, 674, 74, 308, 674, 74};
const PROGMEM uint16_t D_Inv_TL_4[] = {18, 308, 500, 900, 512, 350, 950, 512, 500, 900, 614, 674, 74, 410, 524, 124, 410, 674, 74};
const PROGMEM uint16_t D_Inv_TL_5[] = {18, 308, 350, 950, 512, 350, 950, 512, 350, 950, 614, 674, 74, 410, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_TL_6[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};

//InverseTurnright
const PROGMEM uint16_t D_Inv_TR_1[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_TR_2[] = {18, 512, 500, 900, 512, 350, 950, 716, 500, 900, 614, 674, 74, 614, 524, 124, 410, 674, 124};
const PROGMEM uint16_t D_Inv_TR_3[] = {18, 512, 350, 950, 512, 350, 950, 716, 350, 950, 614, 674, 74, 614, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_TR_4[] = {18, 410, 350, 950, 614, 500, 900, 614, 350, 950, 716, 524, 124, 512, 674, 74, 512, 524, 124};
const PROGMEM uint16_t D_Inv_TR_5[] = {18, 410, 350, 950, 614, 350, 950, 614, 350, 950, 716, 674, 74, 512, 674, 74, 512, 674, 74};
const PROGMEM uint16_t D_Inv_TR_6[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};

//StepDance
const PROGMEM uint16_t D_StepDance1[] = {18, 366, 408, 420, 510, 408, 420, 656, 408, 420, 656, 616, 604, 511, 616, 604, 367, 616, 604};
const PROGMEM uint16_t D_StepDance2[] = {18, 366, 231, 418, 510, 402, 420, 656, 231, 420, 655, 621, 601, 511, 792, 600, 366, 618, 601};
const PROGMEM uint16_t D_StepDance3[] = {18, 366, 403, 419, 510, 231, 421, 656, 401, 420, 655, 793, 601, 511, 619, 603, 366, 793, 601};
const PROGMEM uint16_t D_StepDance4[] = {18, 411, 407, 419, 512, 407, 419, 614, 406, 420, 614, 618, 604, 511, 616, 603, 410, 616, 604};
const PROGMEM uint16_t D_StepDance5[] = {18, 411, 260, 419, 512, 407, 419, 614, 406, 420, 614, 618, 604, 511, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_StepDance6[] = {18, 411, 405, 420, 512, 260, 419, 614, 406, 420, 615, 620, 604, 511, 617, 603, 409, 617, 603};
const PROGMEM uint16_t D_StepDance7[] = {18, 412, 405, 419, 512, 404, 420, 614, 260, 419, 615, 620, 603, 511, 616, 603, 409, 617, 604};
const PROGMEM uint16_t D_StepDance8[] = {18, 412, 405, 419, 512, 402, 419, 614, 401, 421, 614, 764, 603, 510, 617, 604, 410, 617, 604};
const PROGMEM uint16_t D_StepDance9[] = {18, 413, 405, 417, 512, 405, 419, 614, 406, 420, 614, 627, 603, 510, 734, 603, 409, 617, 606};
const PROGMEM uint16_t D_StepDance10[] = {18, 412, 405, 417, 512, 405, 419, 614, 406, 420, 613, 628, 603, 511, 621, 602, 409, 734, 606};

//Push4leg
const PROGMEM uint16_t D_FourLegPush_1[] = {18, 290, 406, 418, 511, 410, 418, 750, 410, 420, 734, 612, 604, 511, 612, 603, 274, 611, 601};
const PROGMEM uint16_t D_FourLegPush_2[] = {18, 290, 700, 670, 511, 200, 715, 750, 290, 419, 734, 324, 354, 512, 824, 309, 274, 734, 603};
const PROGMEM uint16_t D_FourLegPush_3[] = {18, 290, 490, 343, 511, 197, 716, 750, 284, 421, 734, 534, 681, 511, 821, 306, 274, 736, 599};

//DeadPose
const PROGMEM uint16_t D_Deadpose_1[] = {18, 366, 615, 929, 510, 615, 929, 653, 615, 929, 652, 409, 94, 512, 409, 95, 366, 409, 93};
const PROGMEM uint16_t D_Deadpose_2[] = {18, 368, 190, 930, 512, 190, 930, 653, 190, 930, 652, 834, 94, 512, 834, 94, 367, 834, 94};

//SideWave
const PROGMEM uint16_t D_Sidewave_1[] = {18, 408, 734, 610, 510, 759, 651, 614, 734, 610, 611, 824, 610, 513, 824, 610, 409, 764, 610};
const PROGMEM uint16_t D_Sidewave_2[] = {18, 410, 200, 414, 511, 200, 414, 613, 260, 414, 613, 290, 414, 511, 265, 373, 408, 290, 414};
const PROGMEM uint16_t D_Sidewave_3[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};

//UpdownWave
const PROGMEM uint16_t D_Updownwave_1[] = {18, 410, 692, 686, 512, 544, 568, 613, 399, 418, 611, 332, 338, 510, 480, 456, 408, 616, 601};
const PROGMEM uint16_t D_Updownwave_2[] = {18, 409, 404, 418, 510, 401, 420, 612, 399, 419, 612, 621, 604, 512, 622, 600, 409, 616, 601};
const PROGMEM uint16_t D_Updownwave_3[] = {18, 409, 404, 418, 510, 544, 568, 612, 692, 686, 612, 621, 604, 512, 480, 456, 409, 332, 338};

//Bow
const PROGMEM uint16_t D_Provoke_1[] = {18, 290, 250, 680, 360, 556, 556, 616, 403, 418, 734, 774, 344, 664, 468, 468, 408, 614, 603};
const PROGMEM uint16_t D_Provoke_2[] = {18, 290, 360, 550, 358, 410, 410, 612, 404, 418, 734, 664, 474, 664, 614, 614, 410, 616, 604};
const PROGMEM uint16_t D_Provoke_3[] = {18, 290, 600, 600, 360, 547, 559, 611, 398, 418, 734, 424, 424, 662, 479, 463, 409, 617, 601};
const PROGMEM uint16_t D_Provoke_4[] = {18, 290, 530, 800, 356, 546, 559, 612, 396, 419, 734, 828, 530, 663, 478, 463, 409, 617, 601};
const PROGMEM uint16_t D_Provoke_5[] = {18, 290, 196, 494, 355, 545, 558, 612, 396, 419, 734, 494, 224, 664, 479, 462, 409, 618, 601};

//Dance4Leg
const PROGMEM uint16_t D_FourLegDance_1[] = {18, 410, 403, 419, 511, 403, 419, 614, 403, 418, 613, 621, 605, 512, 619, 604, 410, 616, 603};
const PROGMEM uint16_t D_FourLegDance_2[] = {18, 410, 544, 556, 512, 385, 670, 614, 544, 556, 613, 480, 468, 512, 639, 354, 410, 480, 468};
const PROGMEM uint16_t D_FourLegDance_3[] = {18, 409, 400, 418, 511, 220, 870, 614, 402, 419, 613, 622, 608, 511, 804, 154, 411, 619, 606};
const PROGMEM uint16_t D_FourLegDance_4[] = {18, 409, 534, 558, 512, 313, 769, 615, 537, 557, 613, 620, 608, 511, 509, 231, 411, 620, 609};
const PROGMEM uint16_t D_FourLegDance_5[] = {18, 409, 432, 503, 512, 497, 976, 615, 432, 503, 614, 622, 612, 512, 792, 130, 411, 622, 611};
const PROGMEM uint16_t D_FourLegDance_6[] = {18, 409, 530, 559, 512, 302, 769, 615, 530, 554, 614, 622, 613, 512, 767, 171, 410, 621, 612};
const PROGMEM uint16_t D_FourLegDance_7[] = {18, 411, 404, 416, 512, 515, 793, 613, 404, 415, 615, 490, 466, 512, 711, 255, 409, 487, 467};
const PROGMEM uint16_t D_FourLegDance_8[] = {18, 408, 402, 411, 512, 232, 894, 614, 403, 414, 614, 592, 521, 511, 527, 48, 412, 592, 521};
const PROGMEM uint16_t D_FourLegDance_9[] = {18, 408, 400, 407, 512, 254, 853, 615, 402, 413, 614, 495, 467, 511, 722, 255, 412, 494, 475};

//Flip
const PROGMEM uint16_t D_Flip_1[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};
const PROGMEM uint16_t D_Flip_2[] = {18, 278, 556, 497, 512, 621, 584, 612, 769, 751, 746, 468, 527, 512, 403, 440, 412, 255, 273};
const PROGMEM uint16_t D_Flip_3[] = {18, 245, 790, 560, 540, 520, 455, 795, 200, 685, 779, 234, 464, 484, 504, 569, 229, 824, 339};
const PROGMEM uint16_t D_Flip_4[] = {18, 245, 790, 560, 300, 520, 455, 795, 200, 875, 779, 234, 464, 724, 504, 569, 229, 824, 149};
const PROGMEM uint16_t D_Flip_5[] = {18, 245, 790, 880, 512, 400, 905, 795, 200, 875, 779, 234, 144, 512, 624, 119, 229, 824, 149};
const PROGMEM uint16_t D_Flip_6[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};

//InverseFlip
const PROGMEM uint16_t D_Inv_Flip_1[] = {18, 410, 350, 950, 512, 350, 950, 614, 350, 950, 614, 674, 74, 512, 674, 74, 410, 674, 74};
const PROGMEM uint16_t D_Inv_Flip_2[] = {18, 417, 188, 837, 494, 298, 985, 712, 276, 1023, 634, 799, 167, 530, 679, 98, 348, 752, 0};
const PROGMEM uint16_t D_Inv_Flip_3[] = {18, 525, 660, 930, 470, 190, 870, 665, 200, 1023, 499, 364, 94, 554, 834, 154, 359, 824, 0};
const PROGMEM uint16_t D_Inv_Flip_4[] = {18, 555, 790, 855, 570, 187, 852, 622, 188, 1023, 469, 234, 169, 454, 837, 172, 402, 836, 0};
const PROGMEM uint16_t D_Inv_Flip_5[] = {18, 555, 790, 855, 571, 390, 450, 652, 188, 757, 469, 234, 169, 453, 634, 574, 372, 836, 267};
const PROGMEM uint16_t D_Inv_Flip_6[] = {18, 410, 408, 420, 512, 408, 420, 614, 408, 420, 614, 616, 604, 512, 616, 604, 410, 616, 604};

//Inverse Provoke
const PROGMEM uint16_t D_Inv_Provoke_1[] = {18, 412, 223, 804, 513, 342, 904, 609, 382, 954, 616, 805, 216, 511, 683, 124, 409, 644,  55};
const PROGMEM uint16_t D_Inv_Provoke_2[] = {18, 412, 370, 885, 512, 341, 904, 609, 382, 954, 616, 805, 216, 511, 683, 124, 409, 644,  55};
const PROGMEM uint16_t D_Inv_Provoke_3[] = {18, 411, 224, 803, 513, 342, 904, 609, 382, 956, 616, 654, 139, 511, 683, 124, 409, 644,  55};
const PROGMEM uint16_t D_Inv_Provoke_4[] = {18, 340, 670, 804, 430, 317, 904, 490, 383, 961, 684, 354, 216, 594, 706, 124, 534, 644,  52};
const PROGMEM uint16_t D_Inv_Provoke_5[] = {18, 413, 382, 960, 510, 344, 963, 611, 226, 802, 614, 639,  51, 512, 675,  70, 409, 802, 218};

//Inverse Salute
const PROGMEM uint16_t D_Inv_Salute_1[] = {18, 411, 348, 952, 509, 349, 952, 611, 351, 952, 615, 685,  68, 512, 673,  75, 410, 672,  72};
const PROGMEM uint16_t D_Inv_Salute_2[] = {18, 411, 382, 953, 511, 346, 963, 613, 221, 805, 615, 644,  56, 512, 673,  70, 410, 804, 219};
const PROGMEM uint16_t D_Inv_Salute_3[] = {18, 411, 220, 805, 512, 342, 903, 612, 380, 951, 615, 804, 219, 511, 682, 124, 410, 644,  56};
const PROGMEM uint16_t D_Inv_Salute_4[] = {18, 485, 716, 512, 511, 343, 903, 611, 381, 954, 616, 804, 217, 511, 684, 124, 410, 644,  55};

//Inverse StepDance
const PROGMEM uint16_t D_Inv_StepDance_1[] = {18, 412, 348, 953, 510, 350, 956, 610, 351, 953, 615, 681,  67, 511, 672,  73, 410, 672,  71};
const PROGMEM uint16_t D_Inv_StepDance_2[] = {18, 412, 500, 953, 510, 350, 956, 610, 351, 953, 615, 682,  67, 511, 673,  73, 410, 524,  71};
const PROGMEM uint16_t D_Inv_StepDance_3[] = {18, 412, 346, 952, 510, 500, 958, 610, 351, 953, 615, 681,  67, 511, 524,  71, 410, 674,  71};
const PROGMEM uint16_t D_Inv_StepDance_4[] = {18, 412, 346, 952, 510, 350, 957, 610, 500, 953, 615, 524,  67, 511, 672,  71, 410, 674,  71};

//Inverse UpDown
const PROGMEM uint16_t D_Inv_UpDown_1[] = {18, 411, 350, 951, 513, 350, 950, 612, 350, 951, 615, 674,  74, 512, 674,  74, 410, 674,  73};
const PROGMEM uint16_t D_Inv_UpDown_2[] = {18, 410, 200, 790, 510, 200, 790, 614, 200, 790, 614, 824, 234, 511, 824, 234, 410, 824, 234};
const PROGMEM uint16_t D_Inv_UpDown_3[] = {18, 410, 350, 950, 513, 570, 660, 612, 349, 956, 615, 677,  61, 511, 454, 364, 410, 674,  73};
const PROGMEM uint16_t D_Inv_UpDown_4[] = {18, 411, 210, 790, 510, 740, 630, 614, 215, 788, 614, 813, 237, 512, 284, 394, 410, 817, 235};

//Inverse Rhythm
const PROGMEM uint16_t D_Inv_Rhythm_1[] = {18, 411, 350, 953, 511, 358, 949, 612, 351, 953, 615, 669,  74, 512, 669,  72, 410, 671,  71};
const PROGMEM uint16_t D_Inv_Rhythm_2[] = {18, 411, 350, 953, 585, 358, 949, 612, 680, 685, 614, 669,  74, 439, 668,  72, 410, 344, 339};
const PROGMEM uint16_t D_Inv_Rhythm_3[] = {18, 411, 350, 953, 584, 360, 952, 611, 679, 430, 614, 670,  71, 439, 667,  70, 410, 346, 594};
const PROGMEM uint16_t D_Inv_Rhythm_4[] = {18, 413, 350, 953, 584, 360, 954, 611, 679, 655, 614, 670,  69, 439, 667,  69, 410, 346, 680};
const PROGMEM uint16_t D_Inv_Rhythm_5[] = {18, 413, 350, 953, 584, 361, 959, 612, 679, 369, 614, 670,  68, 439, 667,  69, 410, 346, 344};

//Inverse Left Attack
const PROGMEM uint16_t D_Inv_LAttack_1[] = {18, 411, 350, 954, 511, 359, 956, 611, 353, 953, 615, 667,  72, 514, 668,  69, 410, 668,  70};
const PROGMEM uint16_t D_Inv_LAttack_2[] = {18, 411, 275, 948, 511, 275, 956, 610, 275, 953, 615, 668, 220, 514, 668, 220, 410, 668, 220};
const PROGMEM uint16_t D_Inv_LAttack_3[] = {18, 411, 272, 953, 511, 273, 958, 610, 272, 958, 615, 300,  67, 513, 666, 223, 410, 300,  67};
const PROGMEM uint16_t D_Inv_LAttack_4[] = {18, 411, 272, 957, 512, 273, 959, 611, 272, 960, 512, 455, 215, 513, 663, 223, 512, 455, 215};

//Inverse Right Attack
const PROGMEM uint16_t D_Inv_RAttack_1[] = {18, 411, 351, 955, 510, 359, 958, 610, 354, 954, 615, 664,  71, 514, 667,  69, 410, 667,  68};
const PROGMEM uint16_t D_Inv_RAttack_2[] = {18, 411, 356, 804, 510, 356, 804, 610, 356, 804, 615, 749,  74, 514, 749,  74, 410, 749,  74};
const PROGMEM uint16_t D_Inv_RAttack_3[] = {18, 411, 724, 957, 510, 356, 805, 610, 724, 957, 615, 749,  66, 514, 749,  70, 410, 749,  73};
const PROGMEM uint16_t D_Inv_RAttack_4[] = {18, 512, 569, 809, 510, 357, 805, 512, 569, 809, 615, 749,  58, 514, 749,  66, 410, 749,  71};

//====SampleSequence====
const PROGMEM transition_t D_Initial[]={{0,1},{D_InitialPose,500}};
const PROGMEM transition_t D_Walkforward[]={{0,12},{D_WF_4,100},{D_WF_5,50},{D_WF_1,10},{D_WF_2,100},{D_WF_3,50},{D_WF_1,10},{D_WF_4,100},{D_WF_5,50},{D_WF_1,10},{D_WF_2,100},{D_WF_3,50},{D_WF_1,10}};
const PROGMEM transition_t D_Walkbackward[]={{0,12},{D_WB_2,100},{D_WB_3,50},{D_WB_1,10},{D_WB_4,100},{D_WB_5,50},{D_WB_1,10},{D_WB_2,100},{D_WB_3,50},{D_WB_1,10},{D_WB_4,100},{D_WB_5,50},{D_WB_1,10}};
const PROGMEM transition_t D_Turnleft[]={{0,9},{D_TL_1,30},{D_TL_2,50},{D_TL_3,30},{D_TL_4,50},{D_TL_5,30},{D_TL_2,50},{D_TL_3,30},{D_TL_4,50},{D_TL_5,30}};
const PROGMEM transition_t D_Turnright[]={{0,9},{D_TR_1,30},{D_TR_2,50},{D_TR_3,30},{D_TR_4,50},{D_TR_5,30},{D_TR_2,50},{D_TR_3,30},{D_TR_4,50},{D_TR_5,30}};
const PROGMEM transition_t D_FastWalkforward[]={{0,8},{D_Fast_WF_2,60},{D_Fast_WF_3,50},{D_Fast_WF_4,60},{D_Fast_WF_5,50},{D_Fast_WF_2,60},{D_Fast_WF_3,50},{D_Fast_WF_4,60},{D_Fast_WF_5,50}};
const PROGMEM transition_t D_FastWalkbackward[]={{0,8},{D_Fast_WB_2,60},{D_Fast_WB_3,50},{D_Fast_WB_4,60},{D_Fast_WB_5,50},{D_Fast_WB_2,60},{D_Fast_WB_3,50},{D_Fast_WB_4,60},{D_Fast_WB_5,50}};
const PROGMEM transition_t D_FastTurnleft[]={{0,9},{D_Fast_TL_1,50},{D_Fast_TL_2,50},{D_Fast_TL_3,50},{D_Fast_TL_4,50},{D_Fast_TL_5,50},{D_Fast_TL_2,50},{D_Fast_TL_3,50},{D_Fast_TL_4,50},{D_Fast_TL_5,50}};
const PROGMEM transition_t D_FastTurnright[]={{0,9},{D_Fast_TR_1,50},{D_Fast_TR_2,50},{D_Fast_TR_3,50},{D_Fast_TR_4,50},{D_Fast_TR_5,50},{D_Fast_TR_2,50},{D_Fast_TR_3,50},{D_Fast_TR_4,50},{D_Fast_TR_5,50}};
const PROGMEM transition_t D_Walkleftward[]={{0,9},{D_WL_1,15},{D_WL_2,100},{D_WL_3,40},{D_WL_4,100},{D_WL_1,40},{D_WL_2,100},{D_WL_3,40},{D_WL_4,100},{D_WL_1,15}};
const PROGMEM transition_t D_Walkrightward[]={{0,9},{D_WR_1,15},{D_WR_2,100},{D_WR_3,40},{D_WR_4,100},{D_WR_1,40},{D_WR_2,100},{D_WR_3,40},{D_WR_4,100},{D_WR_1,15}};
const PROGMEM transition_t D_Deadpose[]={{0,3},{D_InitialPose,500},{D_Deadpose_1,500},{D_Deadpose_2,500}};
const PROGMEM transition_t D_FourLegPush[]={{0,7},{D_FourLegPush_1,500},{D_FourLegPush_2,500},{D_FourLegPush_3,500},{D_FourLegPush_2,500},{D_FourLegPush_3,500},{D_FourLegPush_2,500},{D_InitialPose,500}};
const PROGMEM transition_t D_Provoke[]={{0,11},{D_InitialPose,500},{D_Provoke_3,500},{D_Provoke_1,500},{D_Provoke_2,500},{D_Provoke_1,500},{D_Provoke_2,500},{D_Provoke_4,500},{D_Provoke_5,500},{D_Provoke_4,500},{D_Provoke_5,500},{D_Provoke_3,500}};
const PROGMEM transition_t D_Sidewave[]={{0,4},{D_Sidewave_1,500},{D_Sidewave_3,500},{D_Sidewave_2,500},{D_Sidewave_3,500}};
const PROGMEM transition_t D_Updownwave[]={{0,7},{D_Updownwave_2,500},{D_Updownwave_1,500},{D_Updownwave_3,500},{D_Updownwave_2,500},{D_Updownwave_1,500},{D_Updownwave_3,500},{D_Updownwave_2,500}};
const PROGMEM transition_t D_Circlewave[]={{0,11},{D_Updownwave_2,500},{D_Updownwave_1,500},{D_Sidewave_1,500},{D_Updownwave_3,500},{D_Sidewave_2,500},{D_Updownwave_2,500},{D_Sidewave_2,500},{D_Updownwave_3,500},{D_Sidewave_1,500},{D_Updownwave_1,500},{D_Updownwave_2,500}};
const PROGMEM transition_t D_FourLegDance[]={{0,15},{D_FourLegDance_1,500},{D_FourLegDance_2,300},{D_FourLegDance_3,300},{D_FourLegDance_2,300},{D_FourLegDance_3,300},{D_FourLegDance_2,300},{D_FourLegDance_4,300},{D_FourLegDance_5,400},{D_FourLegDance_6,400},{D_FourLegDance_7,300},{D_FourLegDance_8,400},{D_FourLegDance_9,400},{D_FourLegDance_2,500},{D_FourLegDance_3,500},{D_FourLegDance_1,500}};
const PROGMEM transition_t D_StepDance[]={{0,19},{D_StepDance1,50},{D_StepDance2,300},{D_StepDance1,50},{D_StepDance3,300},{D_StepDance1,50},{D_StepDance2,300},{D_StepDance4,50},{D_StepDance5,100},{D_StepDance4,50},{D_StepDance6,100},{D_StepDance4,50},{D_StepDance7,100},{D_StepDance4,50},{D_StepDance10,100},{D_StepDance4,50},{D_StepDance9,100},{D_StepDance4,50},{D_StepDance8,100},{D_StepDance4,50}};
const PROGMEM transition_t D_Flip[]={{0,6},{D_Flip_1,500},{D_Flip_2,500},{D_Flip_3,500},{D_Flip_4,500},{D_Flip_5,500},{D_Flip_6,500}};
const PROGMEM transition_t D_Inv_Initial[]={{0,1},{D_Inv_WF_1,500}};
const PROGMEM transition_t D_Inv_Walkforward[]={{0,9},{D_Inv_WF_1,200},{D_Inv_WF_2,300},{D_Inv_WF_3,100},{D_Inv_WF_4,300},{D_Inv_WF_5,100},{D_Inv_WF_2,300},{D_Inv_WF_3,100},{D_Inv_WF_4,300},{D_Inv_WF_1,200}};
const PROGMEM transition_t D_Inv_Walkbackward[]={{0,9},{D_Inv_WB_1,200},{D_Inv_WB_2,300},{D_Inv_WB_3,100},{D_Inv_WB_4,300},{D_Inv_WB_5,100},{D_Inv_WB_2,300},{D_Inv_WB_3,100},{D_Inv_WB_4,300},{D_Inv_WB_1,200}};
const PROGMEM transition_t D_Inv_Turnleft[]={{0,9},{D_Inv_TL_1,200},{D_Inv_TL_2,300},{D_Inv_TL_3,100},{D_Inv_TL_4,300},{D_Inv_TL_5,100},{D_Inv_TL_2,300},{D_Inv_TL_3,100},{D_Inv_TL_4,300},{D_Inv_TL_6,200}};
const PROGMEM transition_t D_Inv_Turnright[]={{0,9},{D_Inv_TR_1,200},{D_Inv_TR_2,300},{D_Inv_TR_3,100},{D_Inv_TR_4,300},{D_Inv_TR_5,100},{D_Inv_TR_2,300},{D_Inv_TR_3,100},{D_Inv_TR_4,300},{D_Inv_TR_6,200}};
const PROGMEM transition_t D_Inv_Walkleftward[]={{0,9},{D_Inv_WL_1,200},{D_Inv_WL_2,300},{D_Inv_WL_3,100},{D_Inv_WL_4,300},{D_Inv_WL_1,200},{D_Inv_WL_2,300},{D_Inv_WL_3,100},{D_Inv_WL_4,300},{D_Inv_WL_1,200}};
const PROGMEM transition_t D_Inv_Walkrightward[]={{0,9},{D_Inv_WR_1,200},{D_Inv_WR_2,300},{D_Inv_WR_3,100},{D_Inv_WR_4,300},{D_Inv_WR_1,200},{D_Inv_WR_2,300},{D_Inv_WR_3,100},{D_Inv_WR_4,300},{D_Inv_WR_1,200}};
const PROGMEM transition_t D_Inv_Provoke[] = {{0,16} ,{D_Inv_Provoke_1,300} ,{D_Inv_Provoke_2,100} ,{D_Inv_Provoke_1,50} ,{D_Inv_Provoke_3,100} ,{D_Inv_Provoke_1,50} ,{D_Inv_Provoke_2,100} ,{D_Inv_Provoke_1,50} ,{D_Inv_Provoke_3,100} ,{D_Inv_Provoke_1,50} ,{D_Inv_Provoke_2,100} ,{D_Inv_Provoke_1,50} ,{D_Inv_Provoke_3,100} ,{D_Inv_Provoke_1,100} ,{D_Inv_Provoke_4,300} ,{D_Inv_Provoke_5,100} ,{D_Inv_Provoke_1,400}};
const PROGMEM transition_t D_Inv_Salute[] = {{0,7} ,{D_Inv_Provoke_1,500} ,{D_Inv_Salute_3,500} ,{D_Inv_Salute_2,500} ,{D_Inv_Salute_3,500} ,{D_Inv_Salute_4,500} ,{D_Inv_Salute_4,200} ,{D_Inv_Salute_1,500}};
const PROGMEM transition_t D_Inv_StepDance[] = {{0,13} ,{D_Inv_StepDance_1,100} ,{D_Inv_StepDance_2,100} ,{D_Inv_StepDance_1,50} ,{D_Inv_StepDance_3,100} ,{D_Inv_StepDance_1,50} ,{D_Inv_StepDance_4,100} ,{D_Inv_StepDance_1,50} ,{D_Inv_StepDance_2,100} ,{D_Inv_StepDance_1,50} ,{D_Inv_StepDance_3,100} ,{D_Inv_StepDance_1,50} ,{D_Inv_StepDance_4,100} ,{D_Inv_StepDance_1,100}};
const PROGMEM transition_t D_Inv_UpDown[] = {{0,9} ,{D_Inv_UpDown_1,300} ,{D_Inv_UpDown_2,400} ,{D_Inv_UpDown_3,200} ,{D_Inv_UpDown_4,300} ,{D_Inv_UpDown_3,200} ,{D_Inv_UpDown_4,300} ,{D_Inv_UpDown_3,200} ,{D_Inv_UpDown_4,300} ,{D_Inv_UpDown_1,400}};
const PROGMEM transition_t D_Inv_Rhythm[] = {{0,20} ,{D_Inv_Rhythm_1,500} ,{D_Inv_Rhythm_2,500} ,{D_Inv_Rhythm_3,500} ,{D_Inv_Rhythm_2,500} ,{D_Inv_Rhythm_3,500} ,{D_Inv_Rhythm_4,100} ,{D_Inv_Rhythm_5,100} ,{D_Inv_Rhythm_4,80} ,{D_Inv_Rhythm_5,80} ,{D_Inv_Rhythm_4,60} ,{D_Inv_Rhythm_5,60} ,{D_Inv_Rhythm_4,40} ,{D_Inv_Rhythm_5,40} ,{D_Inv_Rhythm_4,40} ,{D_Inv_Rhythm_5,40} ,{D_Inv_Rhythm_4,40} ,{D_Inv_Rhythm_5,40} ,{D_Inv_Rhythm_2,20} ,{D_Inv_Rhythm_3,300} ,{D_Inv_Rhythm_2,20}};
const PROGMEM transition_t D_Inv_LAttack[] = {{0,6} ,{D_Inv_LAttack_1,300} ,{D_Inv_LAttack_2,200} ,{D_Inv_LAttack_3,200} ,{D_Inv_LAttack_4,150} ,{D_Inv_LAttack_3,500} ,{D_Inv_LAttack_1,300}};
const PROGMEM transition_t D_Inv_RAttack[] = {{0,6} ,{D_Inv_RAttack_1,300} ,{D_Inv_RAttack_2,200} ,{D_Inv_RAttack_3,200} ,{D_Inv_RAttack_4,150} ,{D_Inv_RAttack_3,500} ,{D_Inv_RAttack_1,300}};
const PROGMEM transition_t D_Inv_Flip[]={{0,6},{D_Inv_Flip_1,500},{D_Inv_Flip_2,500},{D_Inv_Flip_3,500},{D_Inv_Flip_4,500},{D_Inv_Flip_5,500},{D_Inv_Flip_6,500}};

////==== User Sequence Setup ====////
#define ActionNo_1    D_Walkforward
#define ActionNo_2    D_Walkbackward
#define ActionNo_3    D_Walkleftward
#define ActionNo_4    D_Walkrightward
#define ActionNo_5    D_Turnleft
#define ActionNo_6    D_Turnright
#define ActionNo_7    D_FastWalkforward
#define ActionNo_8    D_FastWalkbackward
#define ActionNo_9    D_FastTurnleft
#define ActionNo_10    D_FastTurnright
#define ActionNo_11    D_Inv_Walkforward
#define ActionNo_12    D_Inv_Walkbackward
#define ActionNo_13    D_Inv_Walkleftward
#define ActionNo_14    D_Inv_Walkrightward
#define ActionNo_15    D_Inv_Turnleft
#define ActionNo_16    D_Inv_Turnright
#define ActionNo_17    D_Deadpose
#define ActionNo_18    D_StepDance
#define ActionNo_19    D_Flip
#define ActionNo_20    D_Flip
#define ActionNo_21    D_Updownwave
#define ActionNo_22    D_Circlewave
#define ActionNo_23    D_FourLegDance
#define ActionNo_24    D_StepDance
#define ActionNo_25    D_Sidewave
#define ActionNo_26    D_FourLegPush
#define ActionNo_27    D_FourLegPush
#define ActionNo_28    D_Updownwave
#define ActionNo_29    D_Provoke
#define ActionNo_30    D_FourLegDance
#define ActionNo_31    D_StepDance
#define ActionNo_32    D_Provoke
#define ActionNo_33    D_Circlewave
#define ActionNo_34    D_Sidewave
#define ActionNo_35    D_FourLegDance
#define ActionNo_36    D_FourLegPush
#define ActionNo_37    D_Circlewave
#define ActionNo_38    D_Inv_Provoke
#define ActionNo_39    D_Inv_Initial
#define ActionNo_40    D_Inv_Rhythm
#define ActionNo_41    D_Inv_Salute
#define ActionNo_42    D_Inv_Initial
#define ActionNo_43    D_Inv_Provoke
#define ActionNo_44    D_Inv_LAttack
#define ActionNo_45    D_Inv_Salute
#define ActionNo_46    D_Inv_LAttack
#define ActionNo_47    D_Inv_Flip
#define ActionNo_48    D_Inv_Rhythm
#define ActionNo_49    D_Inv_Flip
#define ActionNo_50    D_Inv_StepDance
#define ActionNo_51    D_Inv_UpDown
#define ActionNo_52    D_Inv_RAttack
#define ActionNo_53    D_Inv_StepDance
#define ActionNo_54    D_Inv_UpDown

////==== User Motion Control ====//// 
//=== Robot Button ====
#define RB_1  23     
#define RB_2  24    
#define RB_3  25    
#define RB_4  26

const int kPostureSpecificActionsCount = 6;
const int kDefaultPostureActionIndex = 1;

const transition_t* InitialPostureAnimation[kPostureSpecificActionsCount] = {NULL, DefaultInitial, D_Inv_Initial};

//=== Remote Control ====
const int RCU_LJU[kPostureSpecificActionsCount] = {0, 1, 11};
const int RCU_LJD[kPostureSpecificActionsCount] = {0, 2, 12};
const int RCU_LJL[kPostureSpecificActionsCount] = {0, 5, 15};
const int RCU_LJR[kPostureSpecificActionsCount] = {0, 6, 16};
const int RCU_RJU[kPostureSpecificActionsCount] = {0, 7, 50};
const int RCU_RJD[kPostureSpecificActionsCount] = {0, 8, 51};
const int RCU_RJL[kPostureSpecificActionsCount] = {0, 9, 13};
const int RCU_RJR[kPostureSpecificActionsCount] = {0, 10, 14};
const int RCU_L1 [kPostureSpecificActionsCount] = {0, 22, 38};
const int RCU_L2 [kPostureSpecificActionsCount] = {0, 17, 40};
const int RCU_L3 [kPostureSpecificActionsCount] = {0, 35, 44};
const int RCU_R1 [kPostureSpecificActionsCount] = {0, 20, 47};
const int RCU_R2 [kPostureSpecificActionsCount] = {0, 21, 45};
const int RCU_R3 [kPostureSpecificActionsCount] = {0, 32, 52};

////==== Music Setup ====////
#define Music_1    "none"   
#define Music_2    "none"  
#define Music_3    "none"   
#define Music_4    "none"  
#define Music_5    "none"  
#define Music_6    "none"  
#define Music_7    "none"  
#define Music_8    "none"  
#define Music_9    "none"  
#define Music_10   "none"  
#define Music_11   "none"  
#define Music_12   "none"  
#define Music_13   "none"  
#define Music_14   "none"  
#define Music_15   "none"  
#define Music_16   "none"  
#define Music_17   "none"  
#define Music_18   "none"  
#define Music_19   "none"  
#define Music_20   "none"  
#define Music_21   "none"  
#define Music_22   "none"  
#define Music_23   "none"  
#define Music_24   "none"  
#define Music_25   "none"  
#define Music_26   "none"  
#define Music_27   "none"  
#define Music_28   "none"  
#define Music_29   "none"  
#define Music_30   "none"  
#define Music_31   "none"  
#define Music_32   "none"  
#define Music_33   "none" 
#define Music_34   "none"  
#define Music_35   "none"  
#define Music_36   "none"  
#define Music_37   "none"  
#define Music_38   "none"  
#define Music_39   "none"  
#define Music_40   "none"  
#define Music_41   "none"  
#define Music_42   "none"  
#define Music_43   "none"  
#define Music_44   "none"  
#define Music_45   "none"  
#define Music_46   "none"  
#define Music_47   "none"  
#define Music_48   "none"  
#define Music_49   "none"  
#define Music_50   "none"  
#define Music_51   "none"  
#define Music_52   "none"  
#define Music_53   "none"  
#define Music_54   "none"     

#endif
