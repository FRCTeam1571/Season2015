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
		setencodermotorposition->Set(CommandBase::encodermotorsubsystem->nextPosition());
	} else if(LowerLift.toggle) {
		setencodermotorposition->Set(CommandBase::encodermotorsubsystem->lastPosition());
	}

	DriveRobot.XVal = xbox->GetRawAxis(DriveRobot.XMap) * 0.8;
	if(DriveRobot.XVal <= xboxDeadZone) DriveRobot.XVal = 0;
	DriveRobot.YVal = xbox->GetRawAxis(DriveRobot.YMap) * 0.8; //Otherwise it bounces around too much
	if(DriveRobot.YVal <= xboxDeadZone) DriveRobot.YVal = 0;

	if(HalveSpeed.pressed) {
		DriveRobot.XVal *= speedReductionValue;
		DriveRobot.YVal *= speedReductionValue;
	}

	driverobot->Drive(DriveRobot.YVal, DriveRobot.XVal);

	MoveToteHolder.XVal = xbox->GetRawAxis(MoveToteHolder.XMap);
	if(MoveToteHolder.XVal <= xboxDeadZone) MoveToteHolder.XVal = 0;

	movetoteholder->Set(MoveToteHolder.XVal);
}
