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
		e(0, 1),
		xbox(0)
	{
		lw = LiveWindow::GetInstance();
	}

private:

	LiveWindow* lw;
	Talon t1;
	Encoder e;
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

	}

	void TeleopPeriodic()
	{
		double y = xbox.GetY();

		if(abs(y) <= 0.1) t1.Set(0);
		t1.Set(xbox.GetY());

		std::cout << e.Get();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

} /* namespace robot */

using namespace robot;

START_ROBOT_CLASS(Robot);
