# Dashboard-2.2

Application made for PUT Solar Dynamics organization. 

## Power used by PCB 
Dashboard is powered by 12V that is being processed by integrated coverter Traco-power. They are giving both 5V and 3,3V of voltage and 1A of current on the output.


## Processors and structure of board
Dashboard is using 32 STM32F103RET6 bit microprocessor with ARM. It has 16 MHz clock. It is functioning as CAN communication medium and has TLE7251V tranceiver. It also manage data that is being displayed on LEDs using UART communication.

Dashboard is also using OLED 0.9" with SSD1309 controllers. It is communicating via I2C communication interface with TCA9548A multiplexer because display units have only one address. Thanks to that we can use 3 displays in line. Displays are connected by four pin Molex picoblade. Dashboard is using displays for showing information about battery charge level, car drive mode(parking, performance etc.) and power consumption.

## Units of dashboard
We can differentiate three operating units in dashboard based on responsibilities they carry out: 

1. Main display is OLED module with 128x64 resolution with 2.7" inch display. It is managed by SPI communication that has additional Data/Commend and Reset signals. It shows current speed of car, info about speed control state and other communicates. It is powered by 15V converter.

2. Dashboard also has alfanumeric OLEDs with 16x2 symbols, that displays current time and distance. It communicates via SPI interface. 

3. There are also LED RGD diodes(100 pieces) that are being placed in a shape of circle. Diodes are being controlled digitally via WS2812B in smd 2020(case). Thanks to diodes communication protocol we can set any color that we write on 8 bits of data per color(RGB8 standard). All of the diodes are connected in series, which gives us less connections overall. Diodes are being managed by STM32F030 microcontroller to take the load of the main microcontroller. It is also using SN74LVC1T45DBVT translator to take te 3,3V output of microcontroller and amp it up to 5V because we need 5V for diodes.


***
Dashboard was programmed using SW4STM32, using C programming language and HAL library.