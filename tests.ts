// tests go here; this will not be compiled when this package is used as a library

let keynote = 0
keynote = ubitbot.frequencyToKey(698)
ubitbot.cppTesting()

basic.forever(() => {
    basic.showIcon(IconNames.Happy)
    basic.pause(300)
    basic.showNumber(keynote)
    basic.pause(300)
})