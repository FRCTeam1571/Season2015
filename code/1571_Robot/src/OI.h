#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include <Joystick.h>

#include "RobotMap.h"
#include "Commands/SetEncoderMotorPositionCommand.h"

typedef struct
{
	int mapping;
	bool pressed = false;
	bool toggle = false;
} Button;

typedef struct
{
	int XMap, YMap;
	double XVal = 0, YVal = 0;
} Stick;

#define Toggle(button, controller) button.toggle = \
	(!button.pressed && controller->GetRawButton(button.mapping))?\
			(button.toggle = (button.toggle)?false:true):\
					(button.toggle = button.toggle);\
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

	Button RaiseLift = {RightBumper};
	Button LowerLift = {LeftBumper};

	Stick DriveRobot = {LeftStickX, LeftStickY};

	void poll();
};

#endif
