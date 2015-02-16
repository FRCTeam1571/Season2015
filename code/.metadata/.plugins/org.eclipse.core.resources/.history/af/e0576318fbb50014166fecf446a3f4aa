#include "WPILib.h"
#include "CommandBase.h"
#include "OI.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow* lw;

	OI* interface;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		interface = new OI();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();

		interface->poll();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

