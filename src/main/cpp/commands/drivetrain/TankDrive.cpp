#include "commands/drivetrain/TankDrive.h"

TankDrive::TankDrive()
{
  Requires(&Drivetrain::GetInstance());
}

// Called once when the command executes
void TankDrive::Initialize()
{
  Drivetrain::GetInstance().Tank(
    OI::GetInstance().controller.GetY(GenericHID::kLeftHand),
    OI::GetInstance().controller.GetY(GenericHID::kRightHand)
  );
}
