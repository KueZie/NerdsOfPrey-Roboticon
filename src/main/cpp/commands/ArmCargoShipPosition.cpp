#include "commands/ArmCargoShipPosition.h"

ArmCargoShipPosition::ArmCargoShipPosition() {
  Requires(Arm::GetInstance());
}

// Called just before this Command runs the first time
void ArmCargoShipPosition::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArmCargoShipPosition::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ArmCargoShipPosition::IsFinished() { return false; }

// Called once after isFinished returns true
void ArmCargoShipPosition::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmCargoShipPosition::Interrupted() {}
