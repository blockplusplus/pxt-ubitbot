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
        _port_id(PCA8574_ID(pin)),
        _pin_id(PCA8574_INTERNAL_PINNAME(pin)),
        port(PCA8574_INSTANCE(pin)) {

        _pin_mask = 1 << _pin_id;

        // Set the pin to diretion in
        port.dir(0x0, _pin_mask, 0xFF);
    }

    int read() {
        return (port.input(_pin_mask) >> _pin_id) & 0x01;
    }

private:

    int _port_id;
    int _pin_id;
    int _pin_mask;
};

class ExpansionDigitalOut {

public:

    PCA8574 & port;

public:

    ExpansionDigitalOut(ExpansionPinName pin, int value) :
        _port_id(PCA8574_ID(pin)),
        _pin_id(PCA8574_INTERNAL_PINNAME(pin)),
        port(PCA8574_INSTANCE(pin)) {

        _pin_mask = 1 << _pin_id;

        // Set the pin to diretion out
        port.dir(_pin_mask, _pin_mask, value << _pin_id);
    }

    void write(int value) {
        port.output((value & 0x01) << _pin_id, _pin_mask);
    }

    void high() {
        write(1);
    }

    void low() {
        write(0);
    }



private:

    int _port_id;
    int _pin_id;
    int _pin_mask;
};


class ExpansionDigitalInOut {

public:

    PCA8574 & port;

public:

    ExpansionDigitalInOut(ExpansionPinName pin, ExpansionPinDirection direction, int value) :
        _port_id(PCA8574_ID(pin)),
        _pin_id(PCA8574_INTERNAL_PINNAME(pin)),
        port(PCA8574_INSTANCE(pin)) {

        _pin_mask = 1 << _pin_id;

        // Set the pin to diretion in / out
        port.dir(direction << _pin_id, _pin_mask, value << _pin_id);
    }

    void input() {
        port.dir(EPIN_INPUT << _pin_id, _pin_mask, 0);
    }

    void output(int value) {
        port.dir(EPIN_OUTPUT << _pin_id, _pin_mask, value << _pin_id);
    }

    int read() {
        return (port.input(_pin_mask) >> _pin_id) & 0x01;
    }

    void write(int value) {
        port.output((value & 0x01) << _pin_id, _pin_mask);
    }

private:

    int _port_id;
    int _pin_id;
    int _pin_mask;
};
#endif