Create by Zachary Wolf
--------------------
About
-------------------- 
Project 2 is an implementation of a countdown timer.
It utilizes a keypad for controls and an LCD for displaying its output.
The program utilizes interrupts to process inputs from the keypad, 
and uses the 1802.cp and 1802.h files to access interace with the LCD. 

Contributor List: Zachary Wolf

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
JDH_1804_Datasheet
https://learn-us-east-1-prod-fleet02-xythos.content.blackboardcdn.com/5e00ea752296c/10911180?X-Blackboard-Expiration=1636189200000&X-Blackboard-Signature=00x8KvA2aCkM9GZc3OivB6Du6x%2B7tZxWd3pPf7mXFhw%3D&X-Blackboard-Client-Id=100310&response-cache-control=private%2C%20max-age%3D21600&response-content-disposition=inline%3B%20filename%2A%3DUTF-8%27%27JDH_1804_Datasheet.pdf&response-content-type=application%2Fpdf&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20211106T030000Z&X-Amz-SignedHeaders=host&X-Amz-Expires=21600&X-Amz-Credential=AKIAZH6WM4PL5SJBSTP6%2F20211106%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=6c3731294b23a2265a3e5a8ec7140dd3feb8974cc11e11d0f83f37f73832c708
  
https://os.mbed.com/platforms/NUCLEO-L4R5ZI/

STM32L4+ Series advanced Arm®-based 32-bit MCUs - Reference manual
https://www.st.com/resource/en/reference_manual/dm00310109-stm32l4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf

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
