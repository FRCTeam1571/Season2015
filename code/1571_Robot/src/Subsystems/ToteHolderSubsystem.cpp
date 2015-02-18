/*
 * ToteHolderSubsystem.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: acohen
 */

#include <Subsystems/ToteHolderSubsystem.h>
#include <RobotMap.h>

ToteHolderSubsystem::ToteHolderSubsystem():
Subsystem("ToteHolderSubsystem")
{
	leftMotor = new Jaguar(ToteHolderLeftJaguarPort);
	rightMotor = new Jaguar(ToteHolderRightJaguarPort);
}

void ToteHolderSubsystem::setSpeed(double speed)
{
	leftMotor->Set(speed);
	rightMotor->Set(-1 * speed);
}
