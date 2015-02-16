/*
 * MoveToteHolderCommand.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: acohen
 */

#include <Commands/MoveToteHolderCommand.h>

MoveToteHolderCommand::MoveToteHolderCommand()
{
	Requires(toteholdersubsystem);
}

void MoveToteHolderCommand::Initialize()
{
	toteholdersubsystem->setDirection(direction);
}

void MoveToteHolderCommand::Execute()
{

}

bool MoveToteHolderCommand::IsFinished()
{
	if(direction == 1) {
		return toteholdersubsystem->extensionSwitch->Get();
	} else if(direction == -1) {
		return toteholdersubsystem->retractionSwitch->Get();
	} else return false;
}

void MoveToteHolderCommand::Interrupted()
{
	Start(); //Can't leave it half open!
}

void MoveToteHolderCommand::End()
{
	direction = 0;
	toteholdersubsystem->setDirection(0);
}

void MoveToteHolderCommand::Open()
{
	direction = 1;
	Start();
}

void MoveToteHolderCommand::Close()
{
	direction = -1;
	Start();
}
