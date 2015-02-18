/*
 * ZeroEncoderMotorCommand.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: acohen
 */

#include <Commands/ZeroEncoderMotorCommand.h>

ZeroEncoderMotorCommand::ZeroEncoderMotorCommand()
{
	Requires(encodermotorsubsystem);
}

void ZeroEncoderMotorCommand::Initialize()
{
	encodermotorsubsystem->setDirection(1);
}

void ZeroEncoderMotorCommand::Execute()
{

}

bool ZeroEncoderMotorCommand::IsFinished()
{
	return !encodermotorsubsystem->resetSwitch->Get();
}

void ZeroEncoderMotorCommand::Interrupted()
{
	encodermotorsubsystem->setDirection(0);
}

void ZeroEncoderMotorCommand::End()
{
	encodermotorsubsystem->setDirection(0);
	encodermotorsubsystem->zero();
}
