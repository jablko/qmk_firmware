# MNT Pocket Reform Keyboard

![MNT Pocket Reform Keyboard](https://www.crowdsupply.com/img/3569/pocket-reform-writing-article.jpg)

seven-inch mini Reform laptop that remains fully open source
RGB backlight, individually programmable
Optical 15 mm trackball
monochrome OLED above the keyboard
https://mntre.com/reform.html#mnt-pocket-reform-reforms-smaller-sibling
https://source.mnt.re/reform/pocket-reform/-/tree/main/pocket-reform-keyboard-kailh-ortho
https://www.crowdsupply.com/mnt/pocket-reform#mechanical-keyboard-with-rgb-backlight
https://www.crowdsupply.com/mnt/pocket-reform/updates/a-technical-walkthrough#input-module

- Keyboard Maintainer: [Jack Bates](https://github.com/jablko)
- Hardware Supported: MNT Pocket Reform Keyboard powered by a [Raspberry Pi RP2040](https://www.raspberrypi.com/documentation/microcontrollers/rp2040.html) microcontroller
- Hardware Availability: On [Crowd Supply](https://www.crowdsupply.com/mnt/pocket-reform#mechanical-keyboard-with-rgb-backlight) for now or as [Open Hardware](https://source.mnt.re/reform/pocket-reform/-/tree/main/pocket-reform-keyboard-kailh-ortho), but will become available in our shop in Winter 2023

Make example for this keyboard (after setting up your build environment):

    make pocket_reform:default

Flashing example for this keyboard:

    make pocket_reform:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

- **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
- **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
- **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
