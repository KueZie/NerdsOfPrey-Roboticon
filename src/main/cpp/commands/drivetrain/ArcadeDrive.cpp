#include "commands/drivetrain/ArcadeDrive.h"

ArcadeDrive::ArcadeDrive()
{
  Requires(&Drivetrain::GetInstance());
}

// Called once when the command executes
void ArcadeDrive::Initialize()
{}

void ArcadeDrive::Execute()
{
  std::cout << "Arcade running...\n";
  Drivetrain::GetInstance().Arcade(
    OI::GetInstance().controller.GetY(GenericHID::kLeftHand),
    OI::GetInstance().controller.GetX(GenericHID::kRightHand)
  );
}

bool ArcadeDrive::IsFinished()
{
  return false;
}