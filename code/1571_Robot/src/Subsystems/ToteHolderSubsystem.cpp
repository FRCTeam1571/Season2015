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
	extensionSwitch = new DigitalInput(ToteHolderExtensionSwitchPort);
	retractionSwitch = new DigitalInput(ToteHolderRetractionSwitchPort);
	leftMotor = new Jaguar(ToteHolderLeftJaguarPort);
	rightMotor = new Jaguar(ToteHolderRightJaguarPort);
}

void ToteHolderSubsystem::setDirection(int dir)
{
	leftMotor->Set(dir);
	rightMotor->Set(dir * -1);
}
