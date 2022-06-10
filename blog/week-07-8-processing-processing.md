# processing Processing

This week I worked on connecting a Processing sketch to an Arduino. To do this
we need a way of communicating between the arduino and processing. The easiest 
way to do this is through Serial, a simple text protocol which the arduino talks.
To allow processing to read or send messages to and from the arduino connect to 
the serial port through processing rather than using the Arduino serial monitor.

We followed [this tutorial](https://www.teachengineering.org/makerchallenges/view/nyu2-2298-sensors-visualization-data-arduino-circuit-challenge)
to connect the two systems.

The below code is a simple example of the processing code required to communicate
with an arduino over the serial port.

```java
// Modified from linked tutorial

import processing.serial.*;

Serial myPort;        // The serial port

void setup () {
  // List all the available serial ports
  // if using Processing 2.1 or later, use Serial.printArray()
  println(Serial.list());

  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[0], 9600);

  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
}

// Serial Event is printed when we receive messages
void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');
}

// If we want to send messages it is done as such.
void loop() {
  myPort.send("Hello Arduino!");
}
```

The Arduino code is similar, we can read and write with the Serial port just
like Processing.

```arduino
  // Full sketch omitted.

 if (Serial.available()) {
    byte in = Serial.read(); // Read a byte from the Serial port
    // Do something with the data.
 }

 Serial.println("Hello Processing!");
```

## Why connect these systems?

Connecting systems is extremely useful as different systems are very good at
different things, for example the arduino can control actuators and measure sensors
but is pretty limited when it comes to processing large amounts of data or displaying
complicated information on a screen. I was particularly excited by this week 
because I have often connected systems to create unified pieces. For example
I connected Pure Data (a digital music software) with processing to create and 
control music produced on my laptop with an external keyboard.

<video style="max-width: 800px; width: auto;" controls>
<source src="/week-6.mp4" type="video/mp4">
</video>

Another example is the Laptop Ensemble which makes extensive use of interconnected
systems to create electronic music with visuals.

<iframe width="560" height="315" src="https://www.youtube.com/embed/A0NG-T8y7gM?start=3008" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
