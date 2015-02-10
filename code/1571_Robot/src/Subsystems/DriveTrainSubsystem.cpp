/*
 * DriveTrainSystem.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#include <Subsystems/DriveTrainSubsystem.h>
#include "../RobotMap.h"

DriveTrainSubsystem::DriveTrainSubsystem():
Subsystem("DriveTrainSubsystem")
{
	left = new Victor(DriveTrainLeftVictorPort);
	right = new Victor(DriveTrainRightVictorPort);
	drive = new RobotDrive(left, right);
}

void DriveTrainSubsystem::setSpeed(double speed, double rotation)
{
	drive->ArcadeDrive(speed, rotation);
}
