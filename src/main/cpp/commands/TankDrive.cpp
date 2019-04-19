/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TankDrive.h"

TankDrive::TankDrive() {
  Requires(Drivetrain::GetInstance());
}

// Called once when the command executes
void TankDrive::Initialize()
{
  Drivetrain::GetInstance()->Tank(OI::GetInstance()->m_Controller->GetRawAxis(1), OI::GetInstance()->m_Controller->GetRawAxis(5));
}
