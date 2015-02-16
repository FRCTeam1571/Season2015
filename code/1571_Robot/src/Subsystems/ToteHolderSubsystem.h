/*
 * ToteHolderSubsystem.h
 *
 *  Created on: Feb 16, 2015
 *      Author: acohen
 */

#ifndef SRC_SUBSYSTEMS_TOTEHOLDERSUBSYSTEM_H_
#define SRC_SUBSYSTEMS_TOTEHOLDERSUBSYSTEM_H_

#include <Commands/Subsystem.h>
#include <DigitalInput.h>
#include <Jaguar.h>

class ToteHolderSubsystem: public Subsystem {
private:
	Jaguar* leftMotor,* rightMotor;
public:
	DigitalInput* extensionSwitch,* retractionSwitch;

	ToteHolderSubsystem();

	void setDirection(int dir);
};

#endif /* SRC_SUBSYSTEMS_TOTEHOLDERSUBSYSTEM_H_ */
