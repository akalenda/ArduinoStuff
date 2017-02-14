#pragma once

namespace Scrappy {
    class MotorDriver {
		public:
			
			virtual void setSpeedTo(int speed);

			virtual int getSpeed();     
			
			virtual void stopNow();
				
			virtual void goForward();
			
			virtual void goBackward();
		};
};
