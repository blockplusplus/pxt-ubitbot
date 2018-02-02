#include "pxt.h"
#include "libs/inc/ubitBot.h"

Bot bot;

using namespace pxt;
namespace ubitbot {
    //%
    int frequencyToKey(int frequency) {
        return max(0, min(127, round(log(frequency/440.0)/log(2) * 12 + 69)));
    }

    //%
    void cppTesting() {
        GreyRegisteredJack grey(bot.rj.j[0]);
        grey.serial.puts("Hello World\n");
        bot.io.port[0].output(0x01, 0x03);
    }
}
