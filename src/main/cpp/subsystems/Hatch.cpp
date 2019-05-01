#include "subsystems/Hatch.h"

Hatch* Hatch::m_Instance = nullptr;

Hatch::Hatch()
  : SimplePneumaticSubsystem("Hatch")
{
  // m_DSolenoid.reset( new frc::DoubleSolenoid(constants::hatch_intake::SOLENOID_IDS[0], constants::hatch_intake::SOLENOID_IDS[1]) );
  // Start retracted
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
}

Hatch* Hatch::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new Hatch();
  return m_Instance;
}

void Hatch::Set(State state)
{
  m_DSolenoid->Set(static_cast<frc::DoubleSolenoid::Value>(state));
  m_State = state;
}

Hatch::State Hatch::GetState()
{
  return m_State;
}

bool Hatch::IsGrabbing()
{
  return m_State == State::FORWARD;
}