// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


SpeedController* RobotMap::driveLSpeed = NULL;
SpeedController* RobotMap::driveRSpeed = NULL;
KomodoDrive* RobotMap::driveControl = NULL;
Gyro* RobotMap::driveGyro = NULL;
SpeedController* RobotMap::driveTurn = NULL;
PIDController* RobotMap::driveGyroPID = NULL;
Encoder* RobotMap::driveLEncoder = NULL;
Encoder* RobotMap::driveREncoder = NULL;
Relay* RobotMap::pincerPinch = NULL;
Relay* RobotMap::tiltTilt = NULL;
Compressor* RobotMap::compressorSysComp = NULL;
Encoder* RobotMap::catapultEncoder = NULL;
CANJaguar* RobotMap::catapultJag2 = NULL;
CANJaguar* RobotMap::catapultJag3 = NULL;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	
	LiveWindow* lw = LiveWindow::GetInstance();
	driveLSpeed = new Talon(1, 2);
	lw->AddActuator("Drive", "LSpeed", (Talon*) driveLSpeed);
	
	driveRSpeed = new Talon(1, 1);
	lw->AddActuator("Drive", "RSpeed", (Talon*) driveRSpeed);
	
	driveControl = new KomodoDrive(driveLSpeed, driveRSpeed, .7, 1);
	
	driveControl->SetSafetyEnabled(true);
        driveControl->SetExpiration(0.1);
        driveControl->SetSensitivity(0.5);
        driveControl->SetMaxOutput(1.0);
        
	driveGyro = new Gyro(1, 1);
	lw->AddSensor("Drive", "Gyro", driveGyro);
	driveGyro->SetSensitivity(0.007);
	driveTurn = new Victor(1, 4);
	//lw->AddActuator("Drive", "Turn", (Victor*) driveTurn);
	
	driveGyroPID = new PIDController(-0.03, 0.0, 0.0,/* F: 0.0, */ driveGyro, driveTurn, 0.02);
	lw->AddActuator("Drive", "GyroPID", driveGyroPID);
	driveGyroPID->SetContinuous(false); driveGyroPID->SetAbsoluteTolerance(0.2); 
        driveGyroPID->SetOutputRange(-1.0, 1.0);
	driveLEncoder = new Encoder(1, 2, 1, 3, false, Encoder::k1X);
	lw->AddSensor("Drive", "LEncoder", driveLEncoder);
	driveLEncoder->SetDistancePerPulse(1.0);
        driveLEncoder->SetPIDSourceParameter(Encoder::kDistance);
        driveLEncoder->Start();
	driveREncoder = new Encoder(1, 9, 1, 10, true, Encoder::k1X);
	lw->AddSensor("Drive", "REncoder", driveREncoder);
	driveREncoder->SetDistancePerPulse(1.0);
        driveREncoder->SetPIDSourceParameter(Encoder::kDistance);
        driveREncoder->Start();
	
        pincerPinch = new Relay(1,2);   
	tiltTilt = new Relay(1,3);      
	lw->AddSensor("El Pincho", "Pinch", pincerPinch);
	lw->AddSensor("El Pincho", "Tilt", tiltTilt);
	
	compressorSysComp = new Compressor(1, 1, 1, 1);
	
	
	catapultEncoder = new Encoder(1, 6, 1, 7, false, Encoder::k4X);
	lw->AddSensor("Catapult", "Encoder", catapultEncoder);
	catapultEncoder->SetDistancePerPulse(1.0);
        catapultEncoder->SetPIDSourceParameter(Encoder::kDistance);
        catapultEncoder->Start();
	catapultJag2 = new CANJaguar(2);
	catapultJag3 = new CANJaguar(3);
	
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
