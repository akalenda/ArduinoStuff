/**
 * @brief 
 * @author Andrew Kalenda
 */

#include "ArduinoMotorShieldR3Driver.hpp"
#include "TwoWheelDrive.hpp"
#include <NewPing.h>

#define TRIGGER_PIN  14
#define ECHO_PIN     15
#define MAX_DISTANCE 200
#define STOPPING_POINT 10

Scrappy::TwoWheelDrive* scrappy;
NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
    Serial.begin(9600);
    pinMode(13, OUTPUT);

    scrappy = new Scrappy::TwoWheelDrive(
      new Scrappy::ArduinoMotorShieldR3(true, false),
      new Scrappy::ArduinoMotorShieldR3(false, false)
    );
    scrappy->setSpeedTo(255);
}

void loop() {
    unsigned int distanceToObject = 111;//DistanceSensor.ping_cm();
    bool mustStopMovingForward = distanceToObject < STOPPING_POINT;
    if (scrappy->isMovingForward() && mustStopMovingForward)
      stopDueToObject(distanceToObject);
    if (Serial.available() > 0) {
        char ch = Serial.read();
        Serial.print("Received: ");
        Serial.println(ch);
        switch(ch) {
          case 'g': (mustStopMovingForward) ? stopDueToObject(distanceToObject) : scrappy->goForward(); break;
          case 'c': scrappy->spinLeft  (); break;
          case 'v': scrappy->goBackward(); break;
          case 'b': scrappy->spinRight (); break;
          case 'q': scrappy->stop      (); exit(0);        
          default : scrappy->stop      ();
        }
        Serial.println(scrappy->toString());
    }
}

void stopDueToObject(int distanceToObject) {
  Serial.print("Stopping due to object at distance ");
  Serial.println(distanceToObject);
  scrappy->stop();
}

