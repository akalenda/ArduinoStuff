/**
 * @brief unfinished library that abstracts control of
 *    Scrappy, my robot car.
 * @author Andrew Kalenda
 */

#include "ArduinoMotorShieldR3Driver.hpp"
#include "TwoWheelDrive.hpp"
#include <NewPing.h>

#define TRIGGER_PIN  7
#define ECHO_PIN     6                                                                                                                                                                                                                                                                                           
#define MAX_DISTANCE 200
#define STOPPING_POINT 10

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int last_period_time;

void setup() {
    last_period_time = millis();
    Serial.begin(9600);

    Scrappy::MotorDriver* a = new Scrappy::ArduinoMotorShieldR3(false);
    a->setSpeedTo(255);

    a->goForward();
    delay(2000);
    a->stopNow();
    delay(2000);
    a->goBackward(); 
    delay(2000);
    a->stopNow();
}

void loop() {
    bluetooth_echo();
    ultrasound_period_ping();
}

void ultrasound_period_ping() {
    int current_time = millis();
    if (current_time - last_period_time > 1000) {
      unsigned int cm = DistanceSensor.ping_cm();
      Serial.print("Distance: ");
      Serial.print(cm);
      Serial.println("cm");
      last_period_time = current_time;
    }
}

void bluetooth_echo(){
  if (Serial.available() > 0) {
    char ch = Serial.read();
    Serial.print("Recieved: ");
    Serial.println(ch);
  }
}

