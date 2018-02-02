#ifndef __UBIT_BOT_H
#define __UBIT_BOT_H

#include "ubitBotConfig.h"
#include "RegisteredJack.h"
#include "PCA8574.h"

class Bot
{
public:
    RegisteredJacks rj;
    IOExpander io;

public:
    Bot() {

    }

};

extern Bot bot;

#endif