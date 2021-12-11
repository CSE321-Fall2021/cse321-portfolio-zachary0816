About
--------------------------------------------------------------------------------------------------
Project 3 is an attempt to create a device to aid the visually impaired using an RTOS system. 
It utilizes a vibration motor and an infared sensor to create a feedback system that allows
someone with poor or no eyesight to detect objects without touching them.
The design also incorporates a red and green LED which fill the same roll as the vibration motor. 
Red activates if the sensor is near an object, and green activates if it is not.
These LEDs both allow a user with poor but still functional eyesight to have a second method of detection, 
aswell as a readily available method to check for a defective motor. 

Contributor List: Zachary Wolf

--------------------
Features
--------------------
Infared sensor for object detection
A rumble motor for physical feedback
Two LEDS, one red one green for clear visual feedback. 
An optional external object that can be manuevered without moving the breadboard (within cable range of the breadboard).

--------------------
Required materials
--------------------

Nucleo L4R5ZI
Micro USB to USB type A cable
A computer running MBED studio
Jumpers
5 Male to female jumpers
Vibration motor
Infared sensor
A Breadboard
Two LEDs, one red, the other green
Two resistors
(optional) A small piece of cardboard, thin sheet of plastic, or other flat lightweight surface that objects could be attached to. 

--------------------
Resoruces and refrences
--------------------

https://os.mbed.com/platforms/NUCLEO-L4R5ZI/
STM32L4+ Series advanced Arm®-based 32-bit MCUs - Reference manual
https://www.st.com/resource/en/reference_manual/dm00310109-stm32l4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
https://os.mbed.com/docs/mbed-os/v6.15/apis/watchdog.html
--------------------
Getting started
--------------------
Setup instructions for the system are outlined in the documentation for the device.
Once assembled, attached the Nucleo to a PC with the code on it, then build and run the code.
The device should now provide LED and vibration feedback when an object is close to the sensor.
If the vibration motor does not activate, check the connection to the vibration motor, as it 
is possible a cable has become loose. 

--------------------
Function declarations used
-------------------- 
void not_detected()
void detected()
Watchdog &Program_watchdog = Watchdog::get_instance();
InterruptIn Trigger_input(PB_3);

--------------------
APIs and Elements
--------------------
No APIs were used, all perihperals were controlled via bitwise control or interrupts
Elemetns used: Red and green LEDs. Vibration motor. Infared sensor. 

--------------------
Custom funcitons
--------------------
void not_detected() - a helper function that deactivates all elements related to detecting a nearby object and deactives the green LED
void detected() - a helper function that activates all elements related that are related detecting a nearby object and deactives the green LED
