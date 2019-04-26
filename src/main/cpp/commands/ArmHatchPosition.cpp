#include "commands/ArmHatchPosition.h"

ArmHatchPosition::ArmHatchPosition() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ArmHatchPosition::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArmHatchPosition::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ArmHatchPosition::IsFinished() { return false; }

// Called once after isFinished returns true
void ArmHatchPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmHatchPosition::Interrupted() {}
