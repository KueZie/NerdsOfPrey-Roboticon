#include "commands/drivetrain/ArcadeDrive.h"

ArcadeDrive::ArcadeDrive() {
  Requires(Drivetrain::GetInstance());
}

// Called once when the command executes
void ArcadeDrive::Initialize()
{}

void ArcadeDrive::Execute()
{
  std::cout << "Arcade running...\n";
  Drivetrain::GetInstance()->Arcade(
    OI::GetInstance()->m_Controller->GetRawAxis(1),
    OI::GetInstance()->m_Controller->GetRawAxis(4)
  );
}

bool ArcadeDrive::IsFinished()
{
  return false;
}