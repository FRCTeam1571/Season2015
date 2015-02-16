/*
 * SetEncoderMotorPositionCommand.h
 *
 *  Created on: Feb 2, 2015
 *      Author: acohen
 */

#ifndef SRC_COMMANDS_SETENCODERMOTORPOSITIONCOMMAND_H_
#define SRC_COMMANDS_SETENCODERMOTORPOSITIONCOMMAND_H_

#include <CommandBase.h>
#include "../Subsystems/EncoderMotorSubsystem.h"

class SetEncoderMotorPositionCommand : public CommandBase {
private:
	double distanceToGo = 0, distanceGone = 0, lastDistanceGone = 0;
	double direction = 0;
	double goal = 0;
	EncoderMotorLiftPosition goalPosition = ZERO;
public:
	SetEncoderMotorPositionCommand();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	void Set(EncoderMotorLiftPosition to);
};

#endif /* SRC_COMMANDS_SETENCODERMOTORPOSITIONCOMMAND_H_ */
