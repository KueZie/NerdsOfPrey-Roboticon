#include "commands/ToggleQuickStop.h"

ToggleQuickStop::ToggleQuickStop()
{
  // Use Requires() here to declare subsystem dependencies
  Requires(&Drivetrain::GetInstance());
}

// Called once when the command executes
void ToggleQuickStop::Initialize() 
{
  auto& drive = Drivetrain::GetInstance();
  drive.SetQuickTurn(!drive.IsQuickTurn());
}
