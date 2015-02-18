#include "OI.h"

OI::OI()
{
	driverobot = new DriveRobotCommand();
	movetoteholder = new MoveToteHolderCommand();
	setencodermotorposition = new SetEncoderMotorPositionCommand();
	zeroencodermotor = new ZeroEncoderMotorCommand();
	xbox = new Joystick(0);
}

void OI::poll()
{
	HalveSpeed.pressed = xbox->GetRawButton(HalveSpeed.mapping);

	Toggle(RaiseLift, xbox);
	Toggle(LowerLift, xbox);

	if(RaiseLift.toggle) {
		if(setencodermotorposition->goalPosition == FULL_TOTE) {
			zeroencodermotor->Start();
			setencodermotorposition->goalPosition = ZERO;
			CommandBase::encodermotorsubsystem->zero();
		}else setencodermotorposition->Set(CommandBase::encodermotorsubsystem->nextPosition());
	} else if(LowerLift.toggle) {
		setencodermotorposition->Set(CommandBase::encodermotorsubsystem->lastPosition());
	}

	ResetLift.pressed = xbox->GetRawButton(ResetLift.mapping);
	if(ResetLift.pressed) {
		zeroencodermotor->Start();
		setencodermotorposition->goalPosition = ZERO;
		CommandBase::encodermotorsubsystem->zero();
	}

	DriveRobot.XVal = xbox->GetRawAxis(DriveRobot.XMap) * 0.8;
	if(std::fabs(DriveRobot.XVal) <= xboxDeadZone) DriveRobot.XVal = 0;
	DriveRobot.YVal = xbox->GetRawAxis(DriveRobot.YMap) * 0.8; //Otherwise it bounces around too much
	if(std::fabs(DriveRobot.YVal) <= xboxDeadZone) DriveRobot.YVal = 0;

	if(HalveSpeed.pressed) {
		DriveRobot.XVal *= speedReductionValue;
		DriveRobot.YVal *= speedReductionValue;
	}

	driverobot->Drive(DriveRobot.YVal, DriveRobot.XVal);

	OpenHolder.pressed = xbox->GetRawButton(OpenHolder.mapping);
	CloseHolder.pressed = xbox->GetRawButton(CloseHolder.mapping);

	if(OpenHolder.pressed) {
		movetoteholder->Set(-0.6);
	} else if(CloseHolder.pressed) {
		movetoteholder->Set(0.6);
	} else movetoteholder->Set(0);
}
