#include "pxt.h"
#include "libs/inc/RegisteredJack.h"

RegisteredJacks rj;


using namespace pxt;
namespace ubitbot {
    //%
    int frequencyToKey(int frequency) {
        return max(0, min(127, round(log(frequency/440.0)/log(2) * 12 + 69)));
    }

    //%
    void cppTesting() {
        GreyRegisteredJack grey(rj.j[0]);
        grey.serial.puts("Hello World\n");
    }
}
