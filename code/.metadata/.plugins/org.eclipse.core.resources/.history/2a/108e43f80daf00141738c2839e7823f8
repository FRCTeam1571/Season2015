#include "OI.h"

OI::OI():
driverobot(),
setencodermotorposition(),
xbox(0)
{

}

void OI::poll()
{
	Toggle(RaiseLift, xbox);
	Toggle(LowerLift, xbox);

	if(RaiseLift.toggle) {
		setencodermotorposition->Set(10);
		RaiseLift.toggle = false;
	} else if(LowerLift.toggle) {
		setencodermotorposition->Set(0);
		LowerLift.toggle = false;
	}

	DriveRobot.XVal = GetAxis(xbox, DriveRobot.XMap);
	DriveRobot.YVal = GetAxis(xbox, DriveRobot.YMap);

	driverobot->Drive(DriveRobot.YVal, -1 * DriveRobot.XVal);
}
