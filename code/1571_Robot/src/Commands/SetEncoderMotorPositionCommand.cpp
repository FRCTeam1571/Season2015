/*
 * SetEncoderMotorPositionCommand.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#include <Commands/SetEncoderMotorPositionCommand.h>

SetEncoderMotorPositionCommand::SetEncoderMotorPositionCommand()
{
	Requires(encodermotorsubsystem);
}

void SetEncoderMotorPositionCommand::Initialize()
{
	distanceToGo = goal - encodermotorsubsystem->getDistance();
	encodermotorsubsystem->setSpeed((distanceToGo > 0)?1:-1);
}

void SetEncoderMotorPositionCommand::Execute()
{

}

bool SetEncoderMotorPositionCommand::IsFinished()
{
	if(abs(goal - encodermotorsubsystem->getDistance()) < 0.1) {
		return true;
	} else return false;
}

void SetEncoderMotorPositionCommand::End()
{
	encodermotorsubsystem->setSpeed(0.0);
}

void SetEncoderMotorPositionCommand::Interrupted()
{
	encodermotorsubsystem->setSpeed(0.0);
}

void SetEncoderMotorPositionCommand::Set(double position)
{
	goal = position;
	Start();
}
