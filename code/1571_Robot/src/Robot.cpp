#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/UpdateEncoderMotorCommand.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	UpdateEncoderMotorCommand* updateencodermotor;
	LiveWindow* lw;

	void RobotInit()
	{
		CommandBase::init();
		updateencodermotor = new UpdateEncoderMotorCommand();
		lw = LiveWindow::GetInstance();

		updateencodermotor->Start();
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
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

