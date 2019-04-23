/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArcadeDrive.h"

ArcadeDrive::ArcadeDrive() {
  Requires(Drivetrain::GetInstance());
}

// Called once when the command executes
void ArcadeDrive::Initialize()
{}

void ArcadeDrive::Execute()
{
  std::cout << "Arcade running...\n";
  Drivetrain::GetInstance()->Arcade(OI::GetInstance()->m_Controller->GetRawAxis(1), OI::GetInstance()->m_Controller->GetRawAxis(4));
}

bool ArcadeDrive::IsFinished()
{
  return false;
}