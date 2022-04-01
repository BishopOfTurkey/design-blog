/*
 * Adapted from Examples -> Servo -> Sweep & Examples -> SparkFun MAX3010x Pluse and Proxmity Sensor Library -> Example_5 Plotter
 * All other code my own.
 * 
 * 
 * Copyright Obi Symons 2021 - Creative Commons Attribution 4.0 International Public License (https://creativecommons.org/licenses/by/4.0/)
 */

#include <Servo.h>
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

Servo myservo;  // create servo object to control a servo

int pos = 0;    // Variable to store the servo position
int top = 180;  // Top and bottom values based for the pen so it doesn't rip itself apart.
int bot = 45;


MAX30105 particleSensor; // Create the sensor object.


void setup() {
  Serial.begin(115200); 
  Serial.println("Initializing...");
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(bot); // Move the servo to the normal writing position

  // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1);
  }
  Serial.println("Place your index finger on the sensor with steady pressure."); 

  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED

  // End Initialize sensor
}

// Variables for storing average heartrate
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred

float beatsPerMinute;
int beatAvg;

// Storing last movement time of the pen.
long lastServoChange = 0;
int updateInterval = 1000;

void loop() {
  // Get the IR value from the heartbeat sensor.
  long irValue = particleSensor.getIR();

  // Find a beat (Uses "heartRate.h" included with the library)
  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    // Calculate the heartrate and the average
    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable

      //Take average of readings
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }
  // Change how often we update the pen based on the average heartrate (between 1 and .3 seconds)
  updateInterval = map(beatAvg, 60, 100, 1000, 300);

  if (millis() - lastServoChange > updateInterval) { // Check if we need to update the pen position
    int variability = map(beatAvg, 60, 100, bot, top); // Map the heart rate to pen positions.
    pos = random(bot, min(variability, top)); // Choice a random position depending on the heartrate
    myservo.write(pos);
    lastServoChange = millis(); // Reset the time since last change.
    Serial.print("Avg BPM="); // print out the Avg BPM for debugging
    Serial.print(beatAvg);

    if (irValue < 50000) // Warn the user they don't have the sensor positioned on their finger.
      Serial.print(" No finger?");

     Serial.println();
  }
}
