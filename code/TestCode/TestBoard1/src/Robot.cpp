// TestBoard code for FRC2015 season
// Team: 1571
// Hello there!  Just messing with the code, everyone.

#include <cmath>

#include "WPILib.h"
#include <BuiltInAccelerometer.h>
#include <Encoder.h>
#include <Gyro.h>
#include <Joystick.h>
#include <RobotDrive.h>
#include <Talon.h>

namespace robot
{

class Robot: public IterativeRobot
{

public:
	Robot():
		lw(NULL),
		t1(0),
		t2(1),
		drive(&t2, &t1),
		xbox(0)
	{
		lw = LiveWindow::GetInstance();
	}

private:

	LiveWindow* lw;
	Talon t1, t2;
	RobotDrive drive;
	Joystick xbox;

	void RobotInit()
	{

	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		t1.Set(0);
		t2.Set(0);
	}

	void TeleopPeriodic()
	{
		drive.ArcadeDrive(xbox.GetY() / 2, xbox.GetX() / -2);
	}

	void TestPeriodic()
	{
		lw->Run();
	}

};

} /* namespace robot */

using namespace robot;

START_ROBOT_CLASS(Robot);
