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
	toteholdersubsystem->setSpeed(speed);
}

void MoveToteHolderCommand::Execute()
{

}

bool MoveToteHolderCommand::IsFinished()
{
	return true;
}

void MoveToteHolderCommand::Interrupted()
{

}

void MoveToteHolderCommand::End()
{

}

void MoveToteHolderCommand::Set(double newSpeed)
{
	speed = newSpeed;
	Start();
}
