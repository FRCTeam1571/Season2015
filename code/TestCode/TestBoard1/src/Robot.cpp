// TestBoard code for FRC2015 season
// Team: 1571
// Hello there!  Just messing with the code

#include "WPILib.h"
#include <Talon.h>

class Robot: public IterativeRobot
{

public:
	Robot():
		lw(NULL),
		t1(0),
		t2(1)
	{
		lw = LiveWindow::GetInstance();
	}

private:

	LiveWindow* lw;
	Talon t1, t2;

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
		t1.Set(1.0f);
		t2.Set(1.0f);
	}

	void TeleopPeriodic()
	{

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
