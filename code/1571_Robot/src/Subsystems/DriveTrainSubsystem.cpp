/*
 * DriveTrainSystem.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#include <Subsystems/DriveTrainSubsystem.h>
#include "../RobotMap.h"

DriveTrainSubsystem::DriveTrainSubsystem():
left(DriveTrainLeftVictorPort),
right(DriveTrainRightVictorPort),
drive(left, right),
gyro(0)
{

}

void DriveTrainSubsystem::setSpeed(double speed, double rotation)
{
	drive->ArcadeDrive(speed, rotation);
}
