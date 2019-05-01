#include "commands/ActuatePneumatic.h"

ActuatePneumatic::ActuatePneumatic(SimplePneumaticSubsystem* subsystem, SimplePneumaticSubsystem::State state)
  : m_State(state), m_PneumaticsSystem(subsystem)
{
  Requires(static_cast<frc::Subsystem*>(subsystem));
}

void ActuatePneumatic::Initialize()
{
  m_PneumaticsSystem->Set(m_State);
}
