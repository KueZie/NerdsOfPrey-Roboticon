/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

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