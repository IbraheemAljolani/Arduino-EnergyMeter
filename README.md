# EnergyMeter
The smart meter is an advanced metering device that records electricity consumption in a more detailed and accurate way compared to traditional meters. Provides real-time data on energy usage, consumption, actual current drawn, and bill value. The Arduino programming language was mainly used to program the device

## Component
1.	ATmega328P
2.	PCB
3.	LCD 16*2
4.	Crystal Oscillator 16MHz
5.	2 Resistance 10K
6.	1 Resistance 2K
7.	2 Capacitance 22pf
8.	1 Capacitance 104pf
9.	Push-Button

1.	ATmega328P:
The high-performance Microchip picoPower® 8-bit AVR® RISC-based microcontroller combines 32 KB ISP Flash memory with read-while-write capabilities, 1024B EEPROM, 2 KB SRAM, 23 general purpose I/O lines, 32 general purpose working registers, three flexible timer/counters with compare modes, internal and external interrupts, serial programmable USART, a byte-oriented Two-Wire serial interface, SPI serial port, a 6-channel 10-bit A/D converter (8-channels in TQFP and QFN/MLF packages), programmable watchdog timer with internal oscillator, and five software selectable power saving modes. The device operates between 1.8-5.5 volts.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/774b3037-fe5f-42e0-8dfc-86bf932781fb)

2.	PCB:
A printed circuit board (PCB) mechanically supports and electrically connects electrical or electronic components using conductive tracks, pads and other features etched from one or more sheet layers of copper laminated onto and/or between sheet layers of a non-conductive substrate. Components are generally soldered onto the PCB to both electrically connect and mechanically fasten them to it.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/48d85e82-6e98-4638-928f-5f7dcf080dd1)

3.	LCD 16*2:
Nowadays, we always use the devices which are made up of LCDs such as CD players, DVD players, digital watches, computers, etc. These are commonly used in the screen industries to replace the utilization of CRTs. Cathode Ray Tubes use huge power when compared with LCDs, and CRTs heavier as well as bigger. These devices are thinner as well power consumption is extremely less.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/9b84ec20-6113-4433-8f82-6c2376c1eeac)

4.	Crystal Oscillator 16MHz:
A crystal oscillator is an electronic oscillator circuit that uses the mechanical resonance of a vibrating crystal of piezoelectric material to create an electrical signal with a constant frequency. This frequency is often used to keep track of time, as in quartz wristwatches, to provide a stable clock signal for digital integrated circuits, and to stabilize frequencies for radio transmitters and receivers. The most common type of piezoelectric resonator used is the quartz crystal, so oscillator circuits incorporating them became known as crystal oscillators.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/b3a67faf-16c9-47cc-a989-8a3c1c60b77f)

5.	Resistance 10K:
Two resistors were used. The first resistance is used for the filter circuit used to improve the input signal received from the meter, the second resistance is used on one end of the pushbutton. The resistor pulls the input to a logical HIGH. If the pin was disconnected, it would float and the values would be unreliable, at best. If it was connected directly to VCC, then a pushed down button would cause a short circuit between VCC and GND and is likely to damage something.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/5e21014b-02be-462d-bcf1-f1992a6ae6a4)

6.	Resistance 2K:
The resistance between the GND pin and the third pin of the LCD is used to improve the brightness of the LCD.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/a493e6ce-c0b0-46ad-b6b8-2913602fdfed)

7.	Capacitance 22pf:
The low-value capacitors (often between 22 and 39pF) in crystal circuits are almost always used to “load” the crystal so that the circuit oscillates at the correct frequency. Although capacitor might have different functions but the main function of oscillator here is to remove harmonics as well as noise which might be harmful for the micro-controller. secondly using external oscillator it produces some sort of voltage which are drained at micro-controller this voltage is absorbed by capacitors.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/b8eada7b-799e-4d40-8406-c9cc2a78f84b)

8.	Capacitance 104pf:
Capacitance is used to supplement the filter circuit consisting of resistance and capacitance used to improve the input signal from the meter.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/1279f6f4-8c40-4bf4-aef3-e8f4cd29ead6)

9.	Push-Button:
The push-button is used for two purposes. The first, when pressed for 5 seconds, restores the readings appearing on the LCD to the zero position. The second works on switching between home and commercial type.

![image](https://github.com/IbraheemAljolani/E-Library/assets/124505345/08c251c9-c25e-4e67-a647-9a5054e28fd6)

## ![breakdown](https://github.com/IbraheemAljolani/Arduino-EnergyMeter/assets/124505345/8ba376eb-198f-474f-ad24-d4d2161a205e) Here's a breakdown of the code:

1. Library and LCD Initialization:
   - The code includes the required libraries and initializes the LiquidCrystal library for the LCD display.
   - Pin assignments for the LCD are defined using the `LiquidCrystal` constructor.

2. Variable Declarations:
   - Various variables are declared to store values related to electricity usage, prices, pulses, counters, and flags.

3. Setup Function:
   - The `setup()` function is called once during initialization.
   - It configures the input pin for the pulse sensor and initializes the LCD.
   - The initial welcome messages are displayed on the LCD.
   - The values of the counter and another variable (`i`) are loaded from the EEPROM.

4. Loop Function:
   - The `loop()` function is executed repeatedly after the setup.
   - It performs the following tasks:
   - Reads the pulse sensor input and stores the value in the `pulse` variable.
   - Reads the state of a push button (`pb1`).
   - Updates counters and flags based on the pulse sensor input.
   - Calculates and displays kilowatt-hour (kWh) usage and current (Amp) on the LCD.
   - Resets the counters and prices if the push button is pressed for a certain duration.
   - Executes different cases based on the value of the variable `i` (representing the pricing tier).
   - Calculates and displays the corresponding price based on the kWh usage and pricing tier.
   - Updates the value of `i` in EEPROM.
