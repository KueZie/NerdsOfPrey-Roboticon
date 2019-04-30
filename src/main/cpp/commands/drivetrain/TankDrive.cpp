#include "commands/drivetrain/TankDrive.h"

TankDrive::TankDrive()
{
  Requires(Drivetrain::GetInstance());
}

// Called once when the command executes
void TankDrive::Initialize()
{
  Drivetrain::GetInstance()->Tank(
    OI::GetInstance()->m_Controller->GetY(GenericHID::kLeftHand),
    OI::GetInstance()->m_Controller->GetY(GenericHID::kRightHand)
  );
}
