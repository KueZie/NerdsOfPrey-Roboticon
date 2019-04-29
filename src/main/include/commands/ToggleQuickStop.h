#pragma once

#include <frc/commands/InstantCommand.h>
#include "subsystems/Drivetrain.h"

class ToggleQuickStop : public frc::InstantCommand {
 public:
  ToggleQuickStop();
  void Initialize() override;
};
