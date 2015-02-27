#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/ZeroEncoderMotorCommand.h"
#include "OI.h"

#include <CameraServer.h>

class Robot: public IterativeRobot
{
private:
	LiveWindow* lw;
	ZeroEncoderMotorCommand* zero;
	OI* interface;
	CameraServer* server;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		zero = new ZeroEncoderMotorCommand();
		interface = new OI();
		server = CameraServer::GetInstance();
		server->StartAutomaticCapture("cam0");
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		zero->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		zero->Start();
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

