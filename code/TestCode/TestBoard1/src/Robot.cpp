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
		t1.Set(0);
	}

	void TeleopPeriodic()
	{
		double RPM = 55;
		bool forward = !xbox.GetRawButton(1);
		double EncoderRate = e.GetRate();
		double EncoderDistance = e.Get();

		SetRPM(&t1, RPM, forward);

		SmartDashboard::PutNumber("Raw encoder data", EncoderDistance);
		SmartDashboard::PutNumber("Lift Motor Supposed RPM", RPM);
		SmartDashboard::PutNumber("Lift Motor actual RPM", abs(EncoderRate) / 71.164 * 7);
		SmartDashboard::PutString("Lift Motor Direction", (forward)?"Forward":"Backward");
	}

	void TestPeriodic()
	{
		lw->Run();
	}

	void SetRPM(Talon* motor, double RPM, bool forwards = true, double MaxRPM = 75){ //Written for specific motor type
		double MotorValue = std::min(RPM / MaxRPM, 1.0);
		SmartDashboard::PutNumber("SetRPM Value", MotorValue);
		motor->Set(MotorValue * ((forwards)?1:-1));
	}

};

} /* namespace robot */

using namespace robot;

START_ROBOT_CLASS(Robot);
