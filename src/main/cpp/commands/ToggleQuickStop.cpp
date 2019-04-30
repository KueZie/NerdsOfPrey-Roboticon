#include "commands/ToggleQuickStop.h"

ToggleQuickStop::ToggleQuickStop()
{
  // Use Requires() here to declare subsystem dependencies
  Requires(Drivetrain::GetInstance());
}

// Called once when the command executes
void ToggleQuickStop::Initialize() 
{
  Drivetrain* drivetrain = Drivetrain::GetInstance();
  drivetrain->SetQuickTurn(!drivetrain->IsQuickTurn());
}
