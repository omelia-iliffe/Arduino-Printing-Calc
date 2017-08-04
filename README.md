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
--- | ---
Top Plastic Shell | Incases and holds buttons, and lcd display
Button Membrane | Made of silicon, Allows for input into the calculator
LCD Screen | Attached to main circuit board, display calculator output
Main circuit board | Has all the confusing things on it. One side is the button array and the other has the lcd screen connector, the printing assembly connector and the microprocessor.
Back Plastic Shell | Houses batteries and Main circuit board
