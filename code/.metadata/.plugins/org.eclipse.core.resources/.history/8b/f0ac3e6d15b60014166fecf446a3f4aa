#include "CommandBase.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "Subsystems/EncoderMotorSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveTrainSubsystem* CommandBase::drivetrainsubsystem = NULL;
EncoderMotorSubsystem* CommandBase::encodermotorsubsystem = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivetrainsubsystem = new DriveTrainSubsystem();
	encodermotorsubsystem = new EncoderMotorSubsystem();
}
