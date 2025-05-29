![GitHub release (latest by date)](https://img.shields.io/github/v/release/KDDaniels/RelayTimer)
![GitHub](https://img.shields.io/github/license/KDDaniels/RelayTimer)
# Relay Timer

Simple timer with a two button interface and LCD screen to show the time remaining. Intended to control a relay but could be used for anything else really.

# Dependencies

I couldn't find it on the PlatformIO library explorer, but this project requires the **[LiquidCrystal_attiny](https://github.com/platisd/ATtiny85-LCD-library/tree/master)** library.

## Features:
- Adjustable time, goes up to 9:59:59 max by default but can be adjusted
- Timer is pausable whenever needed
- Can easily reset the timer while paused or before starting

## Wiring

Intended for an **ATtiny85**, this could definitely be ported to other microcontrollers if needed. Will need slight adjustment due to the direct port register manipulation though.

- NC = No connection
- FB = Function button
- TB = Toggle button
- SCL goes to SCL
- SDA goes to SDA
- Relay goes to a transistor (or straight to a relay if you're feeling bold (don't do that))

```
             ATtiny85
             __   __
 NC <- PB5 =|1 *-* 8|= VCC <- +5v
 FB <- PB3 =|2     7|= PB2 -> SCL
 TB <- PB4 =|3     6|= PB1 -> Relay
GND <- GND =|4_____5|= PB0 -> SDA

```

# Hardware
- ATtiny85 or another microcontroller (will require modification)
- LCD with I<sup>2</sup>C support (I'm using a 1602 screen with a PCF8574 board)
- A relay module
- Two buttons
- A single NPN transistor (I'm using a 2N2222)
- A few resistors (2 4.7kOhm and 5 1kOhm)