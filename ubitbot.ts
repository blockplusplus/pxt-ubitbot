/**
 * Blocks of the ubitBot.
 */
//% weight=85 icon="\uf001" color="#5ea9dd"
namespace ubitbot {


    /**
     * Maps a frequency to a note key
     * @param frequency
     */
    //% blockId=midi_frequency_to_key block="key at %frequency=device_note" useEnumVal=1
    //% advanced=true shim=ubitbot::frequencyToKey
    export function frequencyToKey(frequency: number): number {
        const notes = [8, 9, 9, 10, 10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18, 19, 21, 22, 23, 24, 26, 28, 29, 31, 33, 35, 37, 39, 41, 44, 46, 49, 52, 55, 58, 62, 65, 69, 73, 78, 82, 87, 92, 98, 104, 110, 117, 123, 131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 247, 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976, 2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951, 4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040, 7459, 7902, 8372, 8870, 9397, 9956, 10548, 11175, 11840, 12544];
        let left = 0, right = 0x7f, mid = 69;

        while (right - left > 1) {
            const midf = notes[mid];
            if (frequency == midf)
                return mid;
            else if (frequency < midf) {
                right = mid;
            } else {
                left = mid;
            }
            mid = (left + right) / 2;
        }
        // imprecise match
        return frequency - notes[left] < notes[right] - frequency
            ? left : right;
    }


    /**
     * Testing C++ Functions
     */
    //% blockId=ubitbot_cpp_testing block="cpp testing"
    //% advanced=true shim=ubitbot::cppTesting
    export function cppTesting() : void {
        return;
    }

}