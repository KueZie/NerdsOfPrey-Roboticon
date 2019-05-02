#include "commands/ActuatePneumatic.h"

ActuatePneumatic::ActuatePneumatic(SimplePneumaticSubsystem& subsystem, SimplePneumaticSubsystem::State state)
  : m_State(state), m_PneumaticsSystem(subsystem)
{
  Requires(&subsystem);
}

void ActuatePneumatic::Initialize()
{
  m_PneumaticsSystem.Set(m_State);
}
