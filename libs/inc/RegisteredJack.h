#ifndef __REGISTERED_JACK_H
#define __REGISTERED_JACK_H

#include "mbed.h"
#include "MicroBitConfig.h"
#include "MicroBitPin.h"
#include "ubitBotConfig.h"


enum class EdgeWringPin {
    P0 = 7,  // MICROBIT_ID_IO_P0
    P1 = 8,  // MICROBIT_ID_IO_P1
    P2 = 9,  // MICROBIT_ID_IO_P2
    P8 = 15,  // MICROBIT_ID_IO_P8
    P13 = 20,  // MICROBIT_ID_IO_P13
    P14 = 21,  // MICROBIT_ID_IO_P14
    P15 = 22,  // MICROBIT_ID_IO_P15
    P16 = 23,  // MICROBIT_ID_IO_P16

    NC = -1  // Not connected
};

class RegisteredJack {
public:

    MicroBitPin p[0];
    MicroBitPin p0;
    MicroBitPin p1;
    MicroBitI2C& i2c;

    RegisteredJack(int id, PinName s0, PinName s1, MicroBitI2C & i2cBus) :
        _id(id), _s0(s0), _s1(s1),
        p0(id, s0, PIN_CAPABILITY_ALL),
        p1(id + 1, s1, PIN_CAPABILITY_ALL),
        i2c(i2cBus) {

    }

    ~RegisteredJack() {

    }

    PinName s0() {
        return _s0;
    }

    PinName s1() {
        return _s1;
    }

    int id() {
        return _id;
    }

protected:
    int _id;
    PinName _s0;
    PinName _s1;
};

class RegisteredJacks {

public:
    RegisteredJack j[0];
    RegisteredJack j0;
    RegisteredJack j1;
    RegisteredJack j2;

    RegisteredJacks() :
        j0(UBITBOT_ID_J0, (PinName)UBITBOT_J0_S0, (PinName)UBITBOT_J0_S1, UBITBOT_I2C_INSTANCE),
        j1(UBITBOT_ID_J1, (PinName)UBITBOT_J1_S0, (PinName)UBITBOT_J1_S1, UBITBOT_I2C_INSTANCE),
        j2(UBITBOT_ID_J2, (PinName)UBITBOT_J2_S0, (PinName)UBITBOT_J2_S1, UBITBOT_I2C_INSTANCE) {

    }
};

class GreyRegisteredJack : public RegisteredJack {

public:

    Serial serial;

    GreyRegisteredJack(RegisteredJack & rj) :
        RegisteredJack(rj),
        serial(rj.s1(), rj.s0()) {

    }


};

class BlueRegisteredJack : public RegisteredJack {

public:
    SPI spi;

    BlueRegisteredJack(RegisteredJack & rj) :
        RegisteredJack(rj),
        spi(rj.s1(), NC, rj.s0(), NC) {

    }

};

#endif