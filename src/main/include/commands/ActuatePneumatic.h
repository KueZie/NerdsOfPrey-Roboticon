#pragma once

#include <frc/commands/InstantCommand.h>
#include "util/SimplePneumaticSubsystem.h"

class ActuatePneumatic : public frc::InstantCommand
{
public:
  ActuatePneumatic(SimplePneumaticSubsystem* subsystem, SimplePneumaticSubsystem::State state);
  void Initialize() override;
private:
  SimplePneumaticSubsystem* m_PneumaticsSystem;
  SimplePneumaticSubsystem::State m_State;
};
