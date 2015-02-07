/*
 * UpdateEncoderMotorCommand.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#include <Commands/UpdateEncoderMotorCommand.h>

UpdateEncoderMotorCommand::UpdateEncoderMotorCommand()
{
	Requires(encodermotorsubsystem);
}

void UpdateEncoderMotorCommand::Initialize()
{
	encodermotorsubsystem->zero();
}

void UpdateEncoderMotorCommand::Execute()
{
	encodermotorsubsystem->update();
}

bool UpdateEncoderMotorCommand::IsFinished()
{
	return false;
}

void UpdateEncoderMotorCommand::End()
{
	//Can't reach; command must be canceled manually
}

void UpdateEncoderMotorCommand::Interrupted()
{
	encodermotorsubsystem->setSpeed(0.0);
}
