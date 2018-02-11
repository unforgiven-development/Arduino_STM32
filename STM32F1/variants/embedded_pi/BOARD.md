# Embedded Pi - Board Info #

This file contains some information about the **Embedded Pi** board.


## General Info ##

+ Contains an **STM32F103RBT6** microcontroller
+ Provides a native **USB** connection to the **STM32** microcontroller
+ Does _not_ contain a **USB-to-serial** _(ie: **FTDI** or similar)_ interface for programming
+ Provides a **JTAG** port, with **SWD** being the default _transport_ for the debug interface
    - The **JTAG** signal **TDI** is used as digital I/O by default
    - The **TDI** signal can be relocated to the **JTAG** header by use of **SJ1** _(solder jumper)_
    - If **TDI** is used, then **D8** becomes unusable
    - In **SWD** mode, **SWO** is provided for trace, in addition to the **SWDIO** and **SWCLK** debug signals
+ Provides __2__ independent hardware **SPI** ports
+ Provides __2__ independent hardware **I2C** ports
+ Provides __2__ independent hardware **U(S)ART** _(serial)_ ports
+ Provides __1__ hardware **CAN** port _(needs an external transceiver)_



## Power Notes ##

This section attempts to describe the **power** capabilities of the board.


### STM32 Power Domains ###

+ The **STM32**'s **VDD** pins are powered by a regulated **+3V3** supply.
+ The **STM32**'s **VSS** pins are connected to the board's **GND** plane.
+ The **STM32**'s **VDDA** and **VSSA** _(analog supply)_ pins are connected to an isolated analog **+3V3** supply
    - The _analog supply_ is isolated from the _primary_ **+3V3** supply and **GND** by means of **10uH** inductors
	- The supply is decoupled by a **1uF** capacitor at the point of isolation
	- There is a **100nF** decoupling capacitor adjacent to the **VDDA** and **VSSA** pins
+ Unfortunately, the **STM32**'s **VBAT** pin is not exposed, and is _directly attached_ to the **+3V3** supply
    - This design choice precludes the option of using a **backup battery** _(such as a **CR2032** "coin cell")_ to
      retain the **RTC** and any **SRAM** which is _battery-backup enabled_.
    - The use of a **VBAT** source enables much easier use of various _low-power modes_, such as **DEEP_SLEEP**
+ The board's **+3V3** supply is provided by an **LPC2985-33DBVR** regulator.


### Selectable IOREF for D0-D13, SDA, SCL ###

The board provides the ability to select the **IOREF** _(**I/O** voltage reference level)_ voltage level for the pins
**D0** to **D13**, as well as **SDA** and **SCL**. Selection of the voltage level is facilitated by **JP1**, which has
**+3V3** and **+5V** as available options. The center pin of **JP1** provides the **IOREF** _(referred to as **DVCC** in
the schematics)_, and should be able to accept any voltage between **+3V3** and **+5V5** if the predefined voltages from
**JP1**'s other pins aren't ideal. The **DVCC** supply feeds the _"high-side"_ (the **B** port) of 4 Texas Instruments
**TXS0108E** 8-bit, non-inverting, bidirectional voltage translators.

While the _"low-side"_ (the **A** port) of the **TXS0108E** accepts voltages from **1.2V** to **3.6V**, it is connected
to the **+3V3** supply the **STM32** uses. The _"high-side"_ (the **B** port) is able to accept voltages in the range of
**1.65V** to **5.5V**, the _"high-side"_ (the **B** port) must be greater than or equal to the _"low-side"_ (the **A**
port), limiting the range to **3.3V** to **5.5V**.

The **TXS0108E** is an extremely versatile, and _high-speed_ translator, providing speeds of **110 mbps** in push-pull
mode, and **1.2 mbps** in open-drain mode; no direction-control signals are needed to acheive these rates. The entire
chip is able to be enabled/disabled by an **OE** input; the **Embedded Pi** uses this **OE** signal for arbitrating the
access to the **D0** to **D13** and **SDA/SCL** pins. **JP3** allows the **Raspberry Pi** to control these pins, via the
Raspberry Pi's GPIO I/O header **JP5**. **JP4** allows the **STM32** access to these pins. By having both pins in place,
both the **STM32** and **Raspberry Pi** would be able to access these pins, in which case, arbitration would need to be
performed manually, in software. Additionally, this configuration would allow communication between the **STM32** and
the **Raspberry Pi**, a useful example of which might be configuring the **Raspberry Pi** as an **SPI master**, and the
**STM32** as a **SPI slave**, using the SPI **nSS** pin of the **Raspberry Pi** as an output, and the **STM32** an input
pin. Additionally, in a configuration such as this, the roles could be reversed via software, and additional **SPI** bus
peripherals could be connected to the common bus, and controlled by **GPIO** on the **Raspberry Pi** and/or **STM32**.

For additional information on the **TXS0108E**, refer to its [datasheet][1].















[1]:	<http://www.ti.com/lit/ds/symlink/txs0108e.pdf>
