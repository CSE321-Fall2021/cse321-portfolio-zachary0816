-------------------
About
-------------------
Project Description: The code refrenced in this document invovles usage of a button and an LED.
The program creates a thread that reacts to a flag that is triggered by a button. 
Upon seeing this flag, this program will activate and deactive the output LED for 2000 and 500 time units.


Contribitor List: Zachary Wolf


--------------------
Features
--------------------
The LED refrenced in this program has been designed to activate and deactive for set periods of time.
This feature can be activated via button press.


--------------------
Required Materials
--------------------
-Nucleo L4R5ZI

--------------------
Resources and References
--------------------
RM0432 Reference manual:
https://www.st.com/resource/en/reference_manual/dm00310109-stm32l4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf

--------------------
Getting Started
--------------------
Setup is comprised of connecting the computer running the progmra to the Nucleo L4R5ZI.

--------------------
CSE321_project1_zjwolf_corrected_code.cpp:
--------------------
 
There is a os typle tool used to create periodic events with a periepherial.
The name of the file and the contents in here will be entirely updated.
 
Usage of tools dictates that this is not considered a bare metal program.  
Those tools instantiate with a finite reference but they also have a unique object created that is created. 


----------
Elements Declared
----------
Some variables, functions, objects, and APIs are used to make certain items function. 

There are 8 in addition to the header .h file.

----------
API and Built In Elements Used
----------
Thread
DigitalOut
InterruptIn


LED2
Button1


----------
Custom Functions
----------

Instance:
	Inputs:
		None
	Globally referenced items used:
	Iterator, Output, and the printf functions


Button_is_Pressed:
Triggered by rising action of button
    Inputs: None
    Globally referenced items used:
    Flag

Button_is_Released:
Triggered by falling action of button
    Inputs: None
    Globally referenced items used:
    Flag, Iterator

Instance:
    Inputs: None
    Globally referenced items used:
    printf, thread_sleep(), Output, Iterator

