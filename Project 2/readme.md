--------------------
About
-------------------- 
Project 2 is an implementation of a countdown timer.
It utilizes a keypad for controls and an LCD for displaying its output.
The program utilizes interrupts to process inputs from the keypad, 
and uses the 1802.cp and 1802.h files to access interace with the LCD. 

--------------------
Features
--------------------
An external LCD display which will display the time remaining or being set, as well as a short sentence explaining what the time on the screen signifies. 
Keypad for starting, stopping, setting and resetting the timer
3 LEDs to denote when A, B and D have been pressed on the keypad

--------------------
Required materials
--------------------
3 LEDs
Various assorted jumpers/wires
NuceloL4R5ZI
3 1kOhm resistors
C++
MBED studio (macOS version) 
breadboard
4 x 4 Matrix Array 16 key membrane switch keypad
USB a to Micro USB B cable
USB A to USB C adaptor (only required if laptop lacks USB A ports and has USB C) 
Grove-16x2 LCD - model JHD1802M1 

--------------------
Resoruces and refrences
--------------------
  JHD1804Y_YG( Black on Yellow) 1.1.ppt [兼容模式]
  https://os.mbed.com/platforms/NUCLEO-L4R5ZI/
  STM32 Nucleo-144 boards (MB1312) - User manual

--------------------
Getting started
--------------------
The Schematic provided in the documenation should give 
insight in to how to assemble the wiring neaded to run this code. 

--------------------
Function declarations used
-------------------- 
bool started;
bool running;
int row;

--------------------
APIs and Elements
--------------------
Timer time_remaining;
Timer time_set;
LCD_screen (name of LCD object used) 

--------------------
Custom funcitons
--------------------
Each of these funcitons correspond to a press of the keypad
A_pressed();
B_pressed();
C_pressed();
