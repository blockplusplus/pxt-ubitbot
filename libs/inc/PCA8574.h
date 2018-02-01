#ifndef __PCA8574_H
#define __PCA8574_H

#define PCA8574_I2C_BASE_ADDRESS         0x40
#define PCA8574_ADDRESS_BY_ID(id)        (PCA8574_I2C_BASE_ADDRESS | (id & 0x0E))
#define PCA8574_ADDRESS_BY_PIN(pin)      (PCA8574_I2C_BASE_ADDRESS | (pin % 8))
#define PCA8574_INTERNAL_PINNAME(pin)    (pin / 8)

typedef enum {
    EP0 = 0,
    EP1 = 1,
    EP2 = 2,
    EP3 = 3,
    EP4 = 4,
    EP5 = 5,
    EP6 = 7,
    EP8 = 8,
    EP9 = 9,
    EP10 = 10,
    EP11 = 11,
    EP12 = 12,
    EP13 = 13,
    EP14 = 14,
    EP15 = 15

} ExpansionPinName;

typedef enum {
    EPIN_INPUT = 0,
    EPIN_OUTPUT = 1
} ExpansionPinDirection;


class PCA8574
{

public:
    PCA8574(int id, PinName interruptPin, MicroBitI2C & i2c) :
        _id(id), _i2c(i2c),
        event(interruptPin),
        _address(PCA8574_ADDRESS_BY_ID(id)), _dir(0) {

        // Currently, We don't have to implement the interrrupt
        event.mode(PullUp);

        // First read to clear interrupt
        read();
    }

    int id() {
        return _id;
    }

    void dir(uint8_t direction, uint8_t mask, uint8_t value) {
        uint8_t dir = direction & mask;
        uint8_t output = value & mask;
        uint8_t data = (~dir) & output;

        write(data);

        _dir = dir;
    }

    uint8_t input(uint8_t mask) {
        uint8_t data;
        data = read();

        return data & mask;
    }

    void output(uint8_t value, uint8_t mask) {
        uint8_t out = value & mask;
        uint8_t data = (~_dir) & out;

        write(data);
    }


private:

    void write(uint8_t value) {
        uint8_t data[1];
        data[0] = value;

        _i2c.write(_address, (const char *)data, 1);
    }

    uint8_t read() {
        uint8_t data[1];
        data[0] = 0;
        _i2c.read(_address, (char *)data, 1);

        return data[0];
    }

private:
    MicroBitI2C & _i2c;

    // Currently, We don't have to implement the interrrupt.
    // Or we should use the InterruptIn class
    DigitalIn event;
    int _id;
    int _address;
    // bit 7 ~ 0 indicate Pin7 ~ Pin0 direction. 0 means input, 1 means output
    uint8_t _dir;
};

#endif