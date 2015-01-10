#include "WPILib.h"
#include <Joystick.h>
#include <RobotDrive.h>
#include <Talon.h>

class Robot: public IterativeRobot
{

public:
	Robot():
		lw(NULL),
		t1(0),
		t2(1),
		drive(t1, t2),
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

	}

	void TeleopPeriodic()
	{
		drive.ArcadeDrive(xbox);
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
