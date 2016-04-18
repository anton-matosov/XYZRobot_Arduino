#ifndef USER_MOTION_H
#define USER_MOTION_H

#include <avr/pgmspace.h>

//===== User Default Sequence ======
PROGMEM const uint16_t UserPoseExample[] = {18, 263, 759, 372, 650, 467, 555, 373, 650, 512, 512, 339, 684, 269, 754, 633, 390, 512, 512};
PROGMEM const transition_t UserSequenceName[] = {{0,1} ,{UserPoseExample,400}};
//=======================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================
////===== User Motion ======////
//Please Paste Your New Poses and Sequences Here






////==== User Sequence Setup ====////
//Please Change "UserSequenceName" into your new sequence name
#define New115    UserSequenceName
#define New116    UserSequenceName
#define New117    UserSequenceName
#define New118    UserSequenceName
#define New119    UserSequenceName
#define New120    UserSequenceName
#define New121    UserSequenceName
#define New122    UserSequenceName
#define New123    UserSequenceName
#define New124    UserSequenceName
#define New125    UserSequenceName
#define New126    UserSequenceName
#define New127    UserSequenceName
#define New128    UserSequenceName
#define New129    UserSequenceName
#define New130    UserSequenceName
#define New131    UserSequenceName
#define New132    UserSequenceName
#define New133    UserSequenceName
#define New134    UserSequenceName
#define New135    UserSequenceName
#define New136    UserSequenceName
#define New137    UserSequenceName
#define New138    UserSequenceName
#define New139    UserSequenceName
#define New140    UserSequenceName
#define New141    UserSequenceName
#define New142    UserSequenceName
#define New143    UserSequenceName
#define New144    UserSequenceName
#define New145    UserSequenceName
#define New146    UserSequenceName
#define New147    UserSequenceName
#define New148    UserSequenceName
#define New149    UserSequenceName
#define New150    UserSequenceName
#define New151    UserSequenceName
#define New152    UserSequenceName
#define New153    UserSequenceName
#define New154    UserSequenceName
#define New155    UserSequenceName
#define New156    UserSequenceName
#define New157    UserSequenceName
#define New158    UserSequenceName
#define New159    UserSequenceName
#define New160    UserSequenceName
#define New161    UserSequenceName
#define New162    UserSequenceName
#define New163    UserSequenceName
#define New164    UserSequenceName
#define New165    UserSequenceName
#define New166    UserSequenceName
#define New167    UserSequenceName
#define New168    UserSequenceName
#define New169    UserSequenceName
#define New170    UserSequenceName
#define New171    UserSequenceName
#define New172    UserSequenceName
#define New173    UserSequenceName
#define New174    UserSequenceName
#define New175    UserSequenceName
#define New176    UserSequenceName
#define New177    UserSequenceName
#define New178    UserSequenceName
#define New179    UserSequenceName
#define New180    UserSequenceName
#define New181    UserSequenceName
#define New182    UserSequenceName
#define New183    UserSequenceName
#define New184    UserSequenceName
#define New185    UserSequenceName
#define New186    UserSequenceName
#define New187    UserSequenceName
#define New188    UserSequenceName
#define New189    UserSequenceName
#define New190    UserSequenceName
#define New191    UserSequenceName
#define New192    UserSequenceName
#define New193    UserSequenceName
#define New194    UserSequenceName
#define New195    UserSequenceName
#define New196    UserSequenceName
#define New197    UserSequenceName
#define New198    UserSequenceName
#define New199    UserSequenceName
#define New200    UserSequenceName
#define New201    UserSequenceName
#define New202    UserSequenceName
#define New203    UserSequenceName
#define New204    UserSequenceName
#define New205    UserSequenceName
#define New206    UserSequenceName
#define New207    UserSequenceName
#define New208    UserSequenceName
#define New209    UserSequenceName
#define New210    UserSequenceName
#define New211    UserSequenceName
#define New212    UserSequenceName
#define New213    UserSequenceName
#define New214    UserSequenceName
#define New215    UserSequenceName
#define New216    UserSequenceName
#define New217    UserSequenceName
#define New218    UserSequenceName
#define New219    UserSequenceName
#define New220    UserSequenceName
#define New221    UserSequenceName
#define New222    UserSequenceName
#define New223    UserSequenceName
#define New224    UserSequenceName
#define New225    UserSequenceName
#define New226    UserSequenceName
#define New227    UserSequenceName
#define New228    UserSequenceName
#define New229    UserSequenceName
#define New230    UserSequenceName
#define New231    UserSequenceName
#define New232    UserSequenceName
#define New233    UserSequenceName
#define New234    UserSequenceName
#define New235    UserSequenceName
#define New236    UserSequenceName
#define New237    UserSequenceName
#define New238    UserSequenceName
#define New239    UserSequenceName
#define New240    UserSequenceName
#define New241    UserSequenceName
#define New242    UserSequenceName
#define New243    UserSequenceName
#define New244    UserSequenceName
#define New245    UserSequenceName
#define New246    UserSequenceName
#define New247    UserSequenceName
#define New248    UserSequenceName
#define New249    UserSequenceName
#define New250    UserSequenceName

////==== User Motion Control ====//// 
//=== Robot Button ====
#define RB_1  34      //default:34 
#define RB_2  33      //default:33
#define RB_3  32      //default:32
#define RB_4  35      //default:35
//=== Remote Control ====
#define RCU_LJU   3   //default:3
#define RCU_LJD   4   //default:4
#define RCU_LJL   5   //default:5
#define RCU_LJR   6   //default:6
#define RCU_RJU  89   //default:89
#define RCU_RJD  88   //default:88
#define RCU_RJL   7   //default:7
#define RCU_RJR   8   //default:8
#define RCU_L1   30   //default:30
#define RCU_L2   25   //default:25
#define RCU_L3   60   //default:60
#define RCU_R1   28   //default:28
#define RCU_R2   29   //default:29
#define RCU_R3  103   //default:103


#endif
