#ifndef __UBIT_BOT_CONFIG_H
#define __UBIT_BOT_CONFIG_H

#define UBITBOT_I2C_INSTANCE             uBit.i2c


#define UBITBOT_ID_START                    1000

#define UBITBOT_ID_J0                    UBITBOT_ID_START
#define UBITBOT_ID_J1                    UBITBOT_ID_J0 + 10
#define UBITBOT_ID_J2                    UBITBOT_ID_J0 + 20

#define UBITBOT_J0_S0                    MICROBIT_ID_IO_P0
#define UBITBOT_J0_S1                    MICROBIT_ID_IO_P13

#define UBITBOT_J1_S0                    MICROBIT_ID_IO_P1
#define UBITBOT_J1_S1                    MICROBIT_ID_IO_P14

#define UBITBOT_J2_S0                    MICROBIT_ID_IO_P2
#define UBITBOT_J2_S1                    MICROBIT_ID_IO_P15

#define UBITBOT_PCA8574_0_INT_PIN        MICROBIT_ID_IO_P16



#endif