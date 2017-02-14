#include <NewPing.h>

/**
 * The pin numbers here depend on where you have the ultrasound
 * sensor connected. If this program doesn't work, trace the wires
 * to find which pins on the motherboard the pins on the sensor are
 * connected to. You may need to try a few different pin numbers.
 * 
 * This uses the NewPing library, which I installed as a zip from
 * here: http://playground.arduino.cc/Code/NewPing
 */

#define TRIGGER_PIN  7
#define ECHO_PIN     6
#define MAX_DISTANCE 200

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned int cm = DistanceSensor.ping_cm();
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println("cm");
  delay(1000);
}
