/**
 * @file ArduinoMotorShieldR3Driver.h
 * @brief Motor device driver for the Arduino Motor Shield R3. For two-wheel drive.
 * @author Andrew Kalenda
 */

#pragma once
#include "MotorDriver.hpp"

namespace Scrappy {
	
    class ArduinoMotorShieldR3 : public MotorDriver {
		public:

      ArduinoMotorShieldR3(bool isMotorA){
        R_DIRECTION_PIN = isMotorA ? 12 : 13;
        R_BRAKE_PIN = isMotorA ? 9 : 8;
        R_SPEED_PIN = isMotorA ? 3 : 11;
        setSpeedTo(0);
        stopNow();
      }

      void setSpeedTo(int speed){
        currentSpeed = speed;
      }

      int getSpeed(){
        return currentSpeed;
      }
      
      void stopNow(){
        digitalWrite(L_SPEED_PIN, 0);
        digitalWrite(R_SPEED_PIN, 0);
        digitalWrite(R_BRAKE_PIN, HIGH);
        digitalWrite(R_BRAKE_PIN, HIGH);
      }
      
      void goForward(){
        digitalWrite(L_DIRECTION_PIN, HIGH);
        digitalWrite(R_DIRECTION_PIN, HIGH);
        digitalWrite(L_BRAKE_PIN, LOW);
        digitalWrite(R_BRAKE_PIN, LOW);
        analogWrite(R_SPEED_PIN, currentSpeed);
        analogWrite(R_SPEED_PIN, currentSpeed);
      }
      
      void goBackward(){
        digitalWrite(L_DIRECTION_PIN, LOW);
        digitalWrite(R_DIRECTION_PIN, LOW);
        digitalWrite(L_BRAKE_PIN, LOW);
        digitalWrite(R_BRAKE_PIN, LOW);
        analogWrite(L_SPEED_PIN, currentSpeed);
        analogWrite(R_SPEED_PIN, currentSpeed);
      }

      void turnLeft(){
        digitalWrite(L_DIRECTION_PIN, LOW);
        digitalWrite(R_DIRECTION_PIN, HIGH);
        digitalWrite(L_BRAKE_PIN, LOW);
        digitalWrite(R_BRAKE_PIN, LOW);
        analogWrite(L_SPEED_PIN, currentSpeed);
        analogWrite(R_SPEED_PIN, currentSpeed);
      }

      void turnRight(){
        digitalWrite(L_DIRECTION_PIN, HIGH);
        digitalWrite(R_DIRECTION_PIN, LOW);
        digitalWrite(L_BRAKE_PIN, LOW);
        digitalWrite(R_BRAKE_PIN, LOW);
        analogWrite(L_SPEED_PIN, currentSpeed);
        analogWrite(R_SPEED_PIN, currentSpeed);
      }
      
		private:
      int L_DIRECTION_PIN = 13;
      int R_DIRECTION_PIN = 12;
      int L_BRAKE_PIN = 8;
      int R_BRAKE_PIN = 9;
      int L_SPEED_PIN = 11;
      int R_SPEED_PIN = 3;
      int currentSpeed;

      void engage(){
        
      }
    };
};
