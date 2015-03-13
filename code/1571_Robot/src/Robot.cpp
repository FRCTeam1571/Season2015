#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/DriveRobotCommand.h"
#include "Commands/ZeroEncoderMotorCommand.h"
#include "OI.h"

#include <CameraServer.h>

#include <ctime>

class Robot: public IterativeRobot
{
private:
	LiveWindow* lw;
	DriveRobotCommand* drive;
	ZeroEncoderMotorCommand* zero;
	OI* interface;
	CameraServer* server;

	time_t autoStart;

	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		drive = new DriveRobotCommand();
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
		autoStart = time(NULL);
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();

		time_t currentTime = time(NULL);
		if(difftime(autoStart, currentTime) < 5) {
			drive->Drive(-0.6, 0.0);
		} else {
			drive->Drive(0.0, 0.0);
		}
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

