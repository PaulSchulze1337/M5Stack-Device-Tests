# Minimal examples for some M5Stack Boards using ENVIII Sensor with PlatformIO

[GO BACK ==>](../README.md)

This example reads the temperature, humidity and pressure from the [ENVIII sensor (SHT30 & QMP6988)](https://docs.m5stack.com/en/unit/envIII) and prints the values to the serial monitor.


## Supported Boards:
- [M5Stack Core2](https://docs.m5stack.com/en/core/core2) (firmware 2.1.9-Core2)
- [M5Stack M5Stick CPlus 1.1](https://docs.m5stack.com/en/core/m5stickc_plus) (firmware v1.14.0)
- [M5Stack CoreInk](https://docs.m5stack.com/en/core/coreink) (firmware v2.1.9, v1.14.0)



## Pinout
All necessary settings regarding I2C pins and I2C bus speed are set in the [platformio.ini](platformio.ini) using predefined macros (build_flags = -D NAME.)

It's crucial to have the correct setting depending on the used board. For an overview of M5Stack boards and their pin outs see: [Readme of M5Unified#Hardware information](https://github.com/m5stack/M5Unified?tab=readme-ov-file#hardware-information)


## Required Libraries
All necessary libraries are included in the [platformio.ini](platformio.ini) file.
- [M5Stack](https://github.com/m5stack/m5stack)
- [M5Unit-ENV](https://github.com/m5stack/M5Unit-ENV)