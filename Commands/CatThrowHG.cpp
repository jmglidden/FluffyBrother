// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "CatThrowHG.h"
CatThrowHG::CatThrowHG() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::catapult);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	SetTimeout(1); //How long to coast before firing - let compressor and drive motor battery demands die off
}
// Called just before this Command runs the first time
void CatThrowHG::Initialize() {
	Robot::tilt->Off();
	Robot::pincer->Off();
	//Moved ROBOTBUILDER code block to Execute().  Move Execute() code back here if catapult is sluggish.
}
// Called repeatedly when this Command is scheduled to run
void CatThrowHG::Execute() {
	if (IsTimedOut()){
		Robot::catapult->ResetEncoder();
		Robot::catapult->Enable();
		Robot::catapult->SetSetpoint(265.0);
	}
	else
		Robot::drive->LockHeading();
		Robot::drive->UseKomodoDrive(0,0);
}
// Make this return true when this Command no longer needs to run execute()
bool CatThrowHG::IsFinished() {
	return Robot::catapult->OnTarget();//GetPosition()>Robot::catapult->GetSetpoint();
}
// Called once after isFinished returns true
void CatThrowHG::End() {
	Robot::catapult->Disable();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CatThrowHG::Interrupted() {
	End();
}
