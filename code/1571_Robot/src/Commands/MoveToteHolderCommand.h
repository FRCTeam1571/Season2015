/*
 * MoveToteHolderCommand.h
 *
 *  Created on: Feb 16, 2015
 *      Author: acohen
 */

#ifndef SRC_COMMANDS_MOVETOTEHOLDERCOMMAND_H_
#define SRC_COMMANDS_MOVETOTEHOLDERCOMMAND_H_

#include <CommandBase.h>

class MoveToteHolderCommand: public CommandBase {
private:
	double speed = 0;
public:
	MoveToteHolderCommand();

	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();

	void Set(double newSpeed);
};

#endif /* SRC_COMMANDS_MOVETOTEHOLDERCOMMAND_H_ */
