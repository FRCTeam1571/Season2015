#ifndef OI_H
#define OI_H

#include "WPILib.h"

#include "Commands/SetEncoderMotorPositionCommand.h"

class OI
{
private:
	SetEncoderMotorPositionCommand* setencodermotorposition;
public:
	OI();
};

#endif
