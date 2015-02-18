#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include <Joystick.h>

#include "RobotMap.h"
#include "Commands/DriveRobotCommand.h"
#include "Commands/MoveToteHolderCommand.h"
#include "Commands/SetEncoderMotorPositionCommand.h"
#include "Commands/ZeroEncoderMotorCommand.h"

struct ToggleButton
{
	int mapping;
	bool lastPressed = false;
	bool pressed = false;
	bool toggle = false;

	ToggleButton(int map):
		mapping(map)
	{}
};

struct Stick
{
	int XMap, YMap;
	double XVal = 0, YVal = 0;

	Stick(int x, int y):
		XMap(x),
		YMap(y)
	{}
};

//Checks whether or not a button press should be counted
#define Toggle(button, controller)\
	button.lastPressed = button.pressed;\
	button.pressed = controller->GetRawButton(button.mapping);\
	button.toggle = \
	(button.pressed > button.lastPressed)?\
	true:\
	false;

class OI
{
private:
	DriveRobotCommand* driverobot;
	MoveToteHolderCommand* movetoteholder;
	SetEncoderMotorPositionCommand* setencodermotorposition;
	ZeroEncoderMotorCommand* zeroencodermotor;

	Joystick* xbox;

	double xboxDeadZone = 0.2; //Distance from zero in which input is zero
	double speedReductionValue = 0.7;
public:
	OI();

	ToggleButton HalveSpeed = ToggleButton(XButton);

	ToggleButton RaiseLift = ToggleButton(RightBumper);
	ToggleButton LowerLift = ToggleButton(LeftBumper);
	ToggleButton ResetLift = ToggleButton(YButton);

	ToggleButton OpenHolder = ToggleButton(AButton);
	ToggleButton CloseHolder = ToggleButton(BButton);

	Stick DriveRobot = Stick(LeftStickX, LeftStickY);

	void poll();
};

#endif
