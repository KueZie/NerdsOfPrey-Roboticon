#include "commands/ActuatePneumatic.h"

ActuatePneumatic::ActuatePneumatic(frc::Subsystem* subsystem, SimplePneumaticSystem::State state)
  : m_State(state)
{
  Requires(subsystem);
  m_PneumaticsSystem = reinterpret_cast<SimplePneumaticSystem*>(subsystem);
}

void ActuatePneumatic::Initialize()
{
  m_PneumaticsSystem->Set(m_State);
}
