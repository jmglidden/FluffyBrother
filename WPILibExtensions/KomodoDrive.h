// Class derived from RobotDrive to add a two parameter tunable arcade drive function that provides 
// linear interpolation of turn sensitivities at high and low drive speeds

#ifndef KOMODODRIVE_H_
#define KOMODODRIVE_H_

#include  "WPILib.h"

class  KomodoDrive : public RobotDrive {
public:
	KomodoDrive(SpeedController* left, SpeedController*  right, float fastTurnSens, float slowTurnSens): RobotDrive(left, right){
		a = fastTurnSens;
		b = slowTurnSens;
	}
	~KomodoDrive();
	
	void KomodoArcadeDrive(float throttleCmd, float turnCmd, bool squaredInputs = true);
	
private:
	float a;
	float b;
};

#endif
