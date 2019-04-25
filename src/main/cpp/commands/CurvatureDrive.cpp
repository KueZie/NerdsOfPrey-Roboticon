/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CurvatureDrive.h"

CurvatureDrive::CurvatureDrive() {
  Requires(Drivetrain::GetInstance());
}

void CurvatureDrive::Initialize() {}

void CurvatureDrive::Execute() 
{
  Drivetrain::GetInstance()->Curvature(OI::GetInstance()->m_Controller->GetRawAxis(1),
                                       OI::GetInstance()->m_Controller->GetRawAxis(4));
}

bool CurvatureDrive::IsFinished() { return false; }

// Called once after isFinished returns true
void CurvatureDrive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CurvatureDrive::Interrupted() {}
