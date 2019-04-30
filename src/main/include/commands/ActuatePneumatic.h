#pragma once

#include <frc/commands/InstantCommand.h>
#include "util/SimplePneumaticSystem.h"

class ActuatePneumatic : public frc::InstantCommand
{
public:
  ActuatePneumatic(frc::Subsystem* subsystem, SimplePneumaticSystem::State state);
  void Initialize() override;
private:
  SimplePneumaticSystem* m_PneumaticsSystem;
  SimplePneumaticSystem::State m_State;
};
