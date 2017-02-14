/**
 * @file ArduinoMotorShieldR3Driver.h
 * @brief Motor device driver for the Arduino Motor Shield R3.
 * @author Andrew Kalenda
 */

#pragma once
#include "MotorDriver.hpp"

namespace Scrappy {
	
	class TwoWheelDrive : public MotorDriver {
		public:
			
			/* **************** MotorDriver implementations ******************/
			
			TwoWheelDrive(MotorDriver* leftMotor_, MotorDriver* rightMotor)
				: MotorDriver(),
          state('s'),
					leftMotor(leftMotor_),
					riteMotor(rightMotor){
				leftMotor->stopNow();
				riteMotor->stopNow();
			}
			
			void setSpeedTo(int speed) {
				leftMotor->setSpeedTo(speed);
				riteMotor->setSpeedTo(speed);
			}

			int getSpeed() {
				return leftMotor->getSpeed();
			}
			
			void stopNow() {
				leftMotor->stopNow();
				riteMotor->stopNow();
        state = 's';
			}
				
			void goForward() {
				leftMotor->goForward();
				riteMotor->goForward();
        state = 'f';
			}
			
			void goBackward() {
				leftMotor->goBackward();
				riteMotor->goBackward();
        state = 'b';
			}
			
			/* ****************** Additional members **********************/
			void spinLeft() {
				leftMotor->goBackward();
				riteMotor->goForward();
        state = 'L';
			}
			
			void spinRight() {
				leftMotor->goForward();
				riteMotor->goBackward();
        state = 'R';
			}

      String toString() {
        char out[32];
        sprintf(out, "Moving at (%d,%d), state=%c", leftMotor->getSpeed(), riteMotor->getSpeed(), state);
        return String(out);
      }

      bool isMovingForward() {
        return state == 'f';
      }
			
		private:
		  MotorDriver* leftMotor;
      MotorDriver* riteMotor;
      char state;
	};
};
