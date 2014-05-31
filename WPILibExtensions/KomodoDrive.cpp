// Class derived from RobotDrive to add a two parameter tunable arcade drive function that provides 
// linear interpolation of turn sensitivities at high and low drive speeds

#include "KomodoDrive.h"

/*KomodoDrive::KomodoDrive(SpeedController* left, SpeedController* right, float fastTurnSens, float slowTurnSens) : RobotDrive(left, right){
	a = fastTurnSensitivity;
	b = slowTurnSensitivity;
}*/
void KomodoDrive::KomodoArcadeDrive(float throttleCmd, float turnCmd, bool squaredInputs){
/*	static bool reported = false;
	if (!reported){
		nUsageReporting::report(nUsageReporting::kResourceType_RobotDrive, 2, nUsageReporting::kRobotDrive_ArcadeStandard);
		reported = true;
	}  */

	// local variables to hold the computed PWM values for the motors
	float leftMotorOutput;
	float rightMotorOutput;

	if (squaredInputs){
		// square the inputs (while preserving the sign) to increase fine control while permitting full power
		if (throttleCmd >= 0.0)
			throttleCmd = (throttleCmd * throttleCmd);
		else
			throttleCmd = -(throttleCmd * throttleCmd);
		if (turnCmd >= 0.0)
			turnCmd = (turnCmd * turnCmd);
		else
			turnCmd = -(turnCmd * turnCmd);
	}
	float Y = Limit(throttleCmd);
	float X = Limit(turnCmd);
	
	if (Y > 0.0){
		if (X > 0.0){ //Quadrant I
			leftMotorOutput = Y - b * (X*Y - X);
			rightMotorOutput = Y - X*b - X*Y * (1 + a - b);
		}
		else{ //Quadrant II
			leftMotorOutput = Y + X*b + X*Y * (1 + a - b);
			rightMotorOutput = Y + b * (X*Y - X);
		}
	}
	else{
		if (X > 0.0){ //Quadrant IV
			leftMotorOutput = Y + X*b - X*Y * (1 + a - b);
			rightMotorOutput = Y - b * (X*Y + X);
		}
		else{ //Quadrant III
			leftMotorOutput = Y + b * (X*Y + X);
			rightMotorOutput = Y - X*b + X*Y * (1 + a - b);
		}
	}
	SetLeftRightMotorOutputs(leftMotorOutput, rightMotorOutput);
}
