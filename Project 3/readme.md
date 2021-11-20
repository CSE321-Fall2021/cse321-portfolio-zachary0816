About
--------------------------------------------------------------------------------------------------
Project 3 is an attempt to create a device to aid the visually impaired using an RTOS system. 
It utilizes a vibration motor and an infared sensor to create a feedback system that allows
someone with poor or no eyesight to detect objects without touching them.
The design also incorporates a red and green LED which fill the same roll as the vibration motor. 
Red activates if the sensor is near an object, and green activates if it is not.
These LEDs both allow a user with poor but still functional eyesight to have a second method of detection, 
aswell as a readily available method to check for a defective motor. 

--------------------
Features
--------------------
Infared sensor for object detection
A rumble motor for physical feedback
Two LEDS, one red one green for clear visual feedback. 

--------------------
Required materials
--------------------

Nucleo L4R5ZI
Micro USB to USB type A cable
A computer running MBED studio
Jumpers
Vibration motor
Infrared sensor
A Breadboard
Two LEDs, one red, the other green
Two resistors

--------------------
Resoruces and refrences
--------------------

https://os.mbed.com/platforms/NUCLEO-L4R5ZI/

STM32L4+ Series advanced Arm®-based 32-bit MCUs - Reference manual
https://www.st.com/resource/en/reference_manual/dm00310109-stm32l4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf

--------------------
Getting started
--------------------

--------------------
Function declarations used
-------------------- 
void close();
void not_close();


--------------------
APIs and Elements
--------------------

--------------------
Custom funcitons
--------------------

--------------------
Contributers
--------------------
Zachary Wolf
