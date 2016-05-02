#ifndef CHECK_MASK_H
#define CHECK_MASK_H

#define  LED_WHI_MASK  0x01
#define  LED_BLE_MASK  0x02
#define  LED_GRN_MASK  0x04
#define  LED_RED_MASK  0x08
#define  LED_ALL_MASK  0x0F
#define  LED_NO_MASK   0x00

//status_check_1
#define ID_Setting_mask      0x01
#define Position_mask        0x02
#define Version_mask         0x04

//status_check__2
#define Out_of_Range_mask    0x20
#define timeout_mask         0x40

#define Timeout_Limit 5
#define error_range 5

#endif
