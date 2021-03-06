#include "commands/drivetrain/CurvatureDrive.h"

CurvatureDrive::CurvatureDrive()
{
  Requires(&Drivetrain::GetInstance());
}

void CurvatureDrive::Initialize() {}

void CurvatureDrive::Execute() 
{
  Drivetrain::GetInstance().Curvature(
    OI::GetInstance().controller.GetY(GenericHID::kLeftHand),
    OI::GetInstance().controller.GetX(GenericHID::kRightHand)
  );
}

bool CurvatureDrive::IsFinished() { return false; }

// Called once after isFinished returns true
void CurvatureDrive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CurvatureDrive::Interrupted() {}
