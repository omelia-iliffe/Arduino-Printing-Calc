


[breadboard1]:Arduino-Printing-Calc/Docs/img/breadboard1.png "breadboard1"


# Arduino-Printing-Calc
A quick teardown and hack of the Casio Printing Calculator hr-8l


Lessons learnt when repurposing/upgrading old tech
======

## Step One: Choose a product
When choosing a product there is a number of things to consider
How complex is the thing that i want to tear apart
and How much time do I have to spend on this project.

Some examples of products to choose:
* Original Gameboy Greyscale Camera
* Fax machine Protocol
* Knitting machine

You can choose anything if you come up with a plan and goals.
However some products should be put in the too hard basket.
* pretty much any new tech
* Products that you can't add value too by upgrading them

For my particular project I found a Mint condition Casio HR-8L Portable Printing Calculator for $2 in an op shop.

## Step Two: Come up with a plan and goals
After selecting a product the next step is to figure out what you are trying to achieve. For me with my calculator, I wanted to be able to print a custom string controlled by Arduino.

A plan naturally develop as you begin the project and hit road blocks (of which there will be many)

#### Goal: Print a custom string using an Arduino
##### 1.

## Step Three: Tear it apart and examine
Okay maybe slow down a bit. Don't tear your precious project apart rather slow dissect it with skill and precision. Make a note of how you are taking it apart and ensure that you will be able to put it back together.

After it is in as many pieces as possible, carefully examine each piece. Determine is function and how it works in relation to the whole product.

In relation to the printing calculator, there were not many pieces at all.

Piece | Function
----- | ---
Top Plastic Shell | Incases and holds buttons, and lcd display
Button Membrane | Made of silicon, Allows for input into the calculator
LCD Screen | Attached to main circuit board, display calculator output
Main circuit board | Has all the confusing things on it. One side is the button array and the other has the lcd screen connector, the printing assembly connector and the microprocessor.
Motor assembly | Motor assembly pushes the paper through and prints numbers
Back Plastic Shell | Houses batteries and Main circuit board


## Step Four: Figure out how it works
After taking your product apart, figure out how it works.

For the printing calculator this meant putting batteries in and watching it print. I notices that as it was printing a single motor turned a large complicated arrangement of gears. After examining the printing assembly further I noticed the connection to the main circuit board. The crude ribbon cable was comprised of 8 wires which I knew had to relay all the information needed to print (as there is no other connection to the printing assembly). I desoldered these from the main circuit board and put in there place 0.1" pin headers. This will allow me to use a breadboard to prototype with an Arduino but also allow me to plug it back into the main circuit board.

### The Printing Assembly

I followed the traces from the motor back to the ribbon cable and made a note of which pins they were connected to (pin 3 and 4). Using a variable power supply I found the motor pins polarity and how much current it would use. As the motor used over 200mA I determined I would need a transistor to digitally control it from the Arduino.

Next I followed the ribbon cable wires 5,6,7,8 as they were all going to the same place. I removed a small black cover to reveal a rotary sensor. It is a disk that spins with motor and completed the circuit between 3 different pins on the ribbon.
This is used to identify which character the reels of characters is on.

Finally the most puzzling pins on the ribbon cable lead seemingly into the gear system. I used the variable power supply to run 5v through them whilst powering the motor and discovered that it was triggering something near the reel of characters and making clicking noises. I concluded that it was a small motor that triggered a hammer to type a character.

|Wire Number|Component|Usage
|---|---|---|
|1|Trigger|VCC|
|2|Trigger|GND|
|3|Motor|VCC|
|4|Motor|GND|
|5|Rotary Sensor|Output (14 triggers per revolution)|
|6|Rotary Sensor|Output (1 trigger per revolution)|
|7|Rotary Sensor|VCC|
|8|Rotary Sensor|Output (14 triggers per revolution, offset by 1/28)|


## Step Five: Hack it!

The next step with the printing calculator was to hook it all up to an Arduino uno.
I hooked it up using the wiring diagram shown below

![alt text][breadboard1]
