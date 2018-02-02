#ifndef __EXPANSION_DIGITAL_IN_OUT_H
#define __EXPANSION_DIGITAL_IN_OUT_H

#include "PCA8574.h"
#include "ubitBot.h"

#define PCA8574_INSTANCE(pin)            bot.io.port[PCA8574_ID(pin)]

class ExpansionDigitalIn {

public:

    PCA8574 & port;


public:

    ExpansionDigitalIn(ExpansionPinName pin) :
        port_id(PCA8574_ID(pin)),
        pin_id(PCA8574_INTERNAL_PINNAME(pin)),
        port(PCA8574_INSTANCE(pin)) {

        pin_mask = 1 << pin_id;

        // Set the pin to diretion in
        port.dir(0x0, pin_mask, 0xFF);
    }

    int read() {
        return port.input(pin_mask);
    }

private:

    int port_id;
    int pin_id;
    int pin_mask;
};

#endif