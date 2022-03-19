# Blinky Buzzy － Weeks 1 - 3

## Arduino!
![addressable LEDs!](/leds.png)
_A representation of the Federal Senate using addressable LEDs_

I spent a lot of time with Arduino's back in high school mostly creating flashing
light displays with addressable LEDs. However, it's been a while since I've used 
Arduino as I was wooed away by the fancier microcontrollers such as the ESP32 
with wifi & bluetooth and the STM32 with a fast clock rate & modern(ish) 
CPU architecture.

That being said, I'm looking forward to re-exploring what is a 
wonderful ecosystem and expressive  community of makers.

As I've had a bit of experience building things with Arduino I've combined the
first three weeks of blogs into one.

## Connections and Saying Hello!

In order to say hello (in an arduino kind of way), we need to connect our 
Arduino to the computer and software. Firstly, connect the Arduino to the 
computer via USB, then launch the Arduino
software and set the port to the one connected which is labelled as 
`Arduino Uno` (sometimes you just need to try them all).

Now that the board is connected we can start uploading programs allowing us to
control the inputs and outputs.

In computer science there is a long tradition of test something with a program 
which outputs the words "Hello world!". Because the Arduino doesn't have a
screen (yet) we opt for the much lower tech solution of blinking a LED which
is the "Hello World!" equivalent for Arduino.

```arduino
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT); 
}
void loop() {
  // write the LED pin high turning it on.
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // do nothing for 1000 milliseconds (1 sec)
  // write the LED pin low turning it off.
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // wait again
}
```

Above is the basic blink sketch provided. Arduino makes it very easy for us by
providing simple functions for setting and interacting with the Arduino hardware.
The functions used are annotated in the sketch.

### Blink Different 

Now that we know the Arduino is working we can start changing the sketch to do
something a little more interesting!

**Connecting an external LED**

We can use a breadboard to connect a LED to the Arduino. A 220Ω resistor is
added to reduce the voltage across the LED which is designed for a lower voltage
than 5V. Pin 12 is used as the digital output which is then referenced in the 
code below.

🚨 _Insert picture of breadboard with led and resistor_ 🚨

**East Cardinal Mark**

Instead of simply turning on and off the LED we now flash the LED with the pattern
of an East Cardinal Mark which shows there is safe water to the East of the light
when you are out on a boat!

![led](/basic_led.png)

```arduino
#define PIN 12 // or LED_BUILTIN

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PIN, OUTPUT);
}
void loop() {
  // East cardinal mark
  digitalWrite(PIN, HIGH);
  delay(400);
  digitalWrite(PIN, LOW);
  delay(400);
  digitalWrite(PIN, HIGH);
  delay(400);
  digitalWrite(PIN, LOW);
  delay(400);
  digitalWrite(PIN, HIGH);
  delay(400);
  digitalWrite(PIN, LOW);
  delay(5000);
}
```
![Cardinal East Buoy Light](/cardinal_east_night.gif)
_Cardinal East Buoy Light (shows there is safe water to the East of the light)_
_[Source](https://www.msq.qld.gov.au/Safety/Navigation-buoys-marks-and-beacons)_
