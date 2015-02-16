/*
 * DriveTrainSystem.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#include <Subsystems/DriveTrainSubsystem.h>
#include "../RobotMap.h"\


DriveTrainSubsystem::DriveTrainSubsystem():
Subsystem("DriveTrainSystem")
{
	//
	LeftTop      = new Victor(DriveTrainLeftTopVictorPort);  //Left top
	LeftBottom   = new Victor(DriveTrainLeftBottomVictorPort);  // Left bottom
	RightTop     = new Victor(DriveTrainRightTopVictorPort);  //Right top
	RightBottom  = new Victor(DriveTrainRightBottomVictorPort);  //Right bottom
	drive = new RobotDrive(LeftTop, LeftBottom, RightTop, RightBottom);
}

void DriveTrainSubsystem::setSpeed(double speed, double rotation)
{
	drive->ArcadeDrive(-1 * speed, -1 * rotation);
}

