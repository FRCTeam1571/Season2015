#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

const int DriveTrainLeftVictorPort = 0;
const int DriveTrainRightVictorPort = 1;

const int EncoderMotorEncoderPortA = 0;
const int EncoderMotorEncoderPortB = 1;
const int EncoderMotorTalonPort = 2;

//Xbox controller mapping
const int AButton = 1;
const int BButton = 2;
const int XButton = 3;
const int YButton = 4;
const int LeftBumper = 5;
const int RightBumper = 6;
const int BackButton = 7;
const int StartButton = 8;

const int LeftStickX = 1;
const int LeftStickY = 2;
const int Triggers = 3;
const int RightStickX = 4;
const int RightStickY = 5;

#endif
