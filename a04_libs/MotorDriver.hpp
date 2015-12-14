#pragma once

namespace Scrappy {
    class MotorDriver {
		public:
			
			virtual void setSpeedTo(int speed);

			virtual int getSpeed();     

			virtual int getMinimumSpeed();
			
			virtual int getMaximumSpeed();
			
			virtual void stop();
				
			virtual void goForward();
			
			virtual void goBackward();
		};
};
