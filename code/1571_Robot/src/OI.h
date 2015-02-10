#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include <Joystick.h>

#include "RobotMap.h"
#include "Commands/DriveRobotCommand.h"
#include "Commands/SetEncoderMotorPositionCommand.h"

struct ToggleButton
{
	int mapping;
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

#define Toggle(button, controller) button.toggle = \
	(!button.pressed && controller->GetRawButton(button.mapping))?\
			(button.toggle = (button.toggle)?false:true):\
			(button.pressed = false);\
	button.pressed = controller->GetRawButton(button.mapping) //Don't touch!

#define GetAxis(controller, map) fmax(xboxDeadZone * ((controller->GetRawAxis(map) > 0)?1:-1),\
		controller->GetRawAxis(map)) //Don't touch!

class OI
{
private:
	DriveRobotCommand* driverobot;
	SetEncoderMotorPositionCommand* setencodermotorposition;

	Joystick* xbox; //Don't access directly

	double xboxDeadZone = 0.2; //Distance from zero in which input is zero
public:
	OI();

	ToggleButton RaiseLift = ToggleButton(RightBumper);
	ToggleButton LowerLift = ToggleButton(LeftBumper);

	Stick DriveRobot = Stick(LeftStickX, LeftStickY);

	void poll();
};

#endif
