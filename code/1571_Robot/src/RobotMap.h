#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

const int DriveSystemLeftVictorPort = 0;
const int DriveSystemRightVictorPort = 1;

const int EncoderMotorEncoderPortA = 0;
const int EncoderMotorEncoderPortB = 1;
const int EncoderMotorTalonPort = 2;

#endif
