/*
 * ZeroEncoderMotorCommand.h
 *
 *  Created on: Feb 16, 2015
 *      Author: acohen
 */

#ifndef SRC_COMMANDS_ZEROENCODERMOTORCOMMAND_H_
#define SRC_COMMANDS_ZEROENCODERMOTORCOMMAND_H_

#include <CommandBase.h>

class ZeroEncoderMotorCommand: public CommandBase {
public:
	ZeroEncoderMotorCommand();

	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

#endif /* SRC_COMMANDS_ZEROENCODERMOTORCOMMAND_H_ */
