/**
 * @file ArduinoMotorShieldR3Driver.h
 * @brief Motor device driver for the Arduino Motor Shield R3.
 * @author Andrew Kalenda
 */

#pragma once
#include "MotorDriver.hpp"

namespace Scrappy {
	static int MIN_SPEED_VALUE = 0;
	static int MAX_SPEED_VALUE = 255;
	static int MOTOR_SWITCH_DELAY = 100; // milliseconds
	static int MOTOR_A = 12;
	static int MOTOR_B = 13;
	static int BRAKE_A = 9;
	static int BRAKE_B = 8;
	static int SPEED_A = 3;
	static int SPEED_B = 11;
	
    class ArduinoMotorShieldR3 : public MotorDriver {
		public:
			/**
			 * @param isMotorA True if this corresponds to Motor A and its pins,
			 *                 false if this corresponds to Motor B and its pins
			 */
			ArduinoMotorShieldR3(bool isMotorA, bool reversePolarity) 
				: MotorDriver(), 
					IS_MOTOR_A(isMotorA),
					PIN_MOTOR(isMotorA ? MOTOR_A : MOTOR_B),
					PIN_BRAKE(isMotorA ? BRAKE_A : BRAKE_B),
					PIN_SPEED(isMotorA ? SPEED_A : SPEED_B),
					currentSpeed(MIN_SPEED_VALUE) {
				stop();
			}

			void setSpeedTo(int speed) {
				if (speed <= MIN_SPEED_VALUE) 
					stop();
				else {
					if (speed > MAX_SPEED_VALUE)
						speed = MAX_SPEED_VALUE;
					analogWrite(PIN_SPEED, speed);
          currentSpeed = speed;
				}
			}

			int getSpeed() {
				return currentSpeed;
			}
			
			int getMinimumSpeed() {
				return MIN_SPEED_VALUE;
			}
			
			int getMaximumSpeed() {
				return MAX_SPEED_VALUE;
			}
			
			void stop() {
				analogWrite(PIN_SPEED, 0);
				digitalWrite(PIN_BRAKE, HIGH);
				delay(MOTOR_SWITCH_DELAY);
				isGoingForward = false;
				isGoingBackward = false;
			}
			
			void goForward() {
				if (isGoingForward) 
					return;
				stop();
				go(HIGH);
				isGoingBackward = false;
				isGoingForward = true;
			}
			
			void goBackward() {
				if (isGoingBackward) 
					return;
				stop();
				go(LOW);
				isGoingForward = false;
				isGoingBackward = true;
			}
			
			bool isMotorA() {
				return IS_MOTOR_A;
			}
			
			bool isMotorB() {
				return !IS_MOTOR_A;
			}

		private:
			bool IS_MOTOR_A;
			int PIN_MOTOR;
			int PIN_BRAKE;
			int PIN_SPEED;
			int currentSpeed;
			bool isGoingForward;
			bool isGoingBackward;
			
			/**
			 * @param direction HIGH for forward or LOW for backward
			 */
			inline void go(uint8_t direction) {
				digitalWrite(PIN_MOTOR, direction);
				digitalWrite(PIN_BRAKE, LOW);
				analogWrite(PIN_SPEED, currentSpeed);
			}
    };
};
