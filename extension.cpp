#include "pxt.h"
#include "libs/inc/RegisteredJack.h"
#include "libs/inc/PCA8574.h"

RegisteredJacks rj;
PCA8574 expander(0, (PinName)UBITBOT_PCA8574_0_INT_PIN, uBit.i2c);


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
