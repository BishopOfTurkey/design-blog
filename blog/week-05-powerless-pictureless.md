# Powerless, Pictureless － Week 4

This week I worked with Harrison to connect a servo motor, stepper motor and a
small display to the Arduino with varying levels of success.

## Stepper Motor

![Stepper shield](https://cdn-learn.adafruit.com/assets/assets/000/009/516/medium800/adafruit_products_steppertest.jpg)
_Source: [Adafruit](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/using-stepper-motors)_

Firstly we followed [this guide from Adafruit](https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/using-stepper-motors)
to connect the stepper motor to the Arduino using the shield.

A stepper motor is a very precise motor capable of powerful yet accurate movement.
Although they can't move very quickly they used extensively in robotics and 3d printing.

The first step was to install
a library to enable communication between the shield and Arduino. This, in theory,
allows us to communicate to the chip on the shield in charge of controlling the
stepper motor. After successfully installing the library and uploading the example
sketch to the board... nothing happened. We checked all the connections and noticed 
that the power LED on the board was off, and we still needed to connect a jumper
to enable power to be drawn through the Arduino. Even after connecting this jumper
nothing happened :(. We did a bit more research we discovered that the shield 
needed to be powered by a external power supply which we didn't have access to.
Since we were at an impasse we tried another actuator.

## Servo Motor
![servo](/360-servo.jpg)

Servo motors are DC motors with a potentiometer connected to them so they can 
know their position. They are simple to control and very versatile with many
different sizes and power levels. One of the main disadvantages is that they 
usually have a small range of about 180 degrees, this limits their application
to actuators which only need to move back and forth rather than continuous 
movement.

The Arduino IDE comes with a built in servo library which makes it very easy to
use them. Simply connect the 5V and Ground wires to power and connect the control
wire to any PWM pin.

Servo Example Sketch:
```arduino
/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 180);   
  myservo.write(val);
  delay(15);
}
```

We successfully did this with a spare servo motor I had!

## Display

![display](/tft_display.jpg)
_That's probably not how it should look :(_

Our final actuator was a small display I had from a previous project a few years
back. I was drawn to this screen as it is a simple way of communicating 
information to the user of a system.

Following [this guide](https://www.electronics-lab.com/project/using-1-44-color-tft-display-ili9163c-arduino/)
from electronics-lab we connected up the wires, installed the library (which was
a major hassle) and uploaded the sample sketch. Unfortunately it did not work,
we were presented with a black screen on a jumbled mess. We didn't have much time
to troubleshoot the issues before this weeks class ended.

## Thoughts

This week gave me a good experience working with and debugging different components.
I saw some good opportunities to use the servo motor in my first project.