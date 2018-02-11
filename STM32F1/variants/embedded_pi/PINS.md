# Embedded Pi - STM32 Port Pinout #

This document describes the connections to each of the **port pins** on the **STM32F103RBT6** microcontroller present
on the **Embedded Pi** development board.


## STM32 Ports ##

The **STM32F103RBT6** has a total of __4__ ports, __3__ of which are __16-bits__ wide. The remaining port, **Port D**,
is __3__ bits wide.

Ports are named **Port A**, **Port B**, _etc._. Individual pins are referred to in the following format: **PX#** -- for
example: **PA0**, **PB3**, **PC15**, _etc._.


## Board Ports ##

The **Embedded Pi** refers to its pins by a number scheme similar to that used by the [Arduino][1], in that pins capable
of **digital I/O** are numbered sequentially, from __0__ to *__n__*, and may also be prepended with the letter **D**, as
**D0**, **D13**, **D18**, _etc._ Pins which have **ADC** _(analog input)_ capability are labeled **A0** to **A_n_**.

There are a few pins that have dedicated functionality, a few pins with duplicated functionality, and a few pins with
certain caveats associated with them. These will be noted below.


## Pin Map ##

Below is the pin map for each port of the microcontroller:


### Port A ###

+ **PA0** - **D25** _(Serial2 **CTS**)_
+ **PA1** - **D24** _(Serial2 **RTS**)_
+ **PA2** - **D23** _(Serial2 **TXD**)_
+ **PA3** - **D22** _(Serial2 **RXD**)_
+ **PA4** - **D32** _(SPI2 **nSS**)_
+ **PA5** - **D35** _(SPI2 **SCK**)_
+ **PA6** - **D34** _(SPI2 **MISO**)_
+ **PA7** - **D33** _(SPI2 **MOSI**)_
+ **PA8** - **D9** _(PWM -- **TIM1_CH1**)_
+ **PA9** - **D26** _(PWM(+) -- **TIM1_CH2**)_
+ **PA10** - **D28** _(PWM(+) -- **TIM1_CH3**)_
+ **PA11** - **USB D-**
+ **PA12** - **USB D+**
+ **PA13** - **JTAG:** _TMS_ -- **SWD:** _SWDIO_
+ **PA14** - **JTAG:** _TCK_ -- **SWD:** _SWCLK_
+ **PA15** - **D8** _or_ **JTAG:** _TDI_ -- selected by **SJ1** _(see **NOTE 1** in the **Caveats** section)_


### Port B ###

+ **PB0** - **D
+ **PB1** - **D
+ **PB2** - **BOOT1**
+ **PB3** - **JTAG:** _TDO_ -- **SWD:** _SWO_ _(**serial wire output**, used for **trace** output)_
+ **PB4** - 
+ **PB5** - **D
+ **PB6** - **D
+ **PB7** - **D
+ **PB8** - **D
+ **PB9** - **D
+ **PB10** - **D
+ **PB11** - **D
+ **PB12** - **D
+ **PB13** - **D
+ **PB14** - **D
+ **PB15** - **D


### Port C ###

+ **PC0** - **D
+ **PC1** - **D
+ **PC2** - **D
+ **PC3** - **D
+ **PC4** - **D
+ **PC5** - **D
+ **PC6** - **D
+ **PC7** - **D
+ **PC8** - **D
+ **PC9** - **D
+ **PC10** - **D
+ **PC11** - **D
+ **PC12** - **D
+ **PC13** - **D
+ **PC14** - **OSC32-IN** _(used by the **32.768kHz** oscillator, **Y1**, located on the board)_
+ **PC15** - **OSC32-OUT** _(used by the **32.768kHz** oscillator, **Y1**, located on the board)_


### Port D ###

+ **PD0** - **OSC-IN** _(used by the _primary_ oscillator, an **8MHz** crystal, located at **Y2** on the board)_
+ **PD1** - **OSC-OUT** _(used by the _primary_ oscillator, an **8MHz** crystal, located at **Y2** on the board)_
+ **PD2** - **D7**


### Misc ###

+ **BOOT0** - Connected to **GND** via a **100k** _pulldown_ resistor, with an on-board push button to for _pullup_ to
              **+3V3** via a **10k** resistor. Additionally, this pin is exposed on **JP7** _(the **"POWER"** header)_.
+ **RESET** - Connected to **+3V3** via a **10k** _pullup_ resistor, with an on-board push button for connection to the
              board's **GND**, and _debounced_ via a **100nF** capacitor to **GND**. Additionally, this pin is exposed
              on **JP7** _(the **"POWER"** header)_. The **RESET** signal is _active-**low**_; pulling to **GND** causes
              the **STM32** to enter _(or be held in)_ **POR** _(power-on reset)_ mode.


## Caveats & Notes ##

This section is comprised of the various caveats found on the board, as well as various other notes regarding design,
layout, and operation of the board.


### NOTE 1: JTAG TDI vs D8 ###

The _port-pin_ **PA15** provides multiple possible functions. It's **primary** _(intended)_ function is **digital I/O**,
located at position **D8**. However, the **JTAG** debug signal **TDI** is also provided by this _port-pin_. Debug is an
important function; **SWD** _(serial wire debug)_ has been implemented as the default for this board, as the majority of
the **JTAG** _port-pins_ also provide **SWD** functionality, which is just as effective.

In certain instances, perhaps if no programmer with **SWD** capability is available, full **JTAG** mode can be enabled
by use of **SJ1** _(solder jumper)_. By ensuring the connection between **SJ1** pins __2__ and __1__ is severed, and the
connection between **SJ1** pins __2__ and __3__ is present, full **JTAG** functionality becomes available on **JP2**,
the board's **JTAG/SWD** _debug header_.

**WARNING:** _If the position of **SJ1** has been altered to enable **JTAG**, the digital I/O at location **D8** will no
             longer function! While this should be obvious, it seemed prudent to provide an additional warning._
