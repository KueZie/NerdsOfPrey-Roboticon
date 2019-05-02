#include "subsystems/HatchSlider.h"

HatchSlider::HatchSlider()
  : SimplePneumaticSubsystem("HatchSlider"),
    m_DSolenoid(constants::hatch_slider::SOLENOID_IDS[0], constants::hatch_slider::SOLENOID_IDS[1])
{
  // Start retracted
  m_DSolenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

HatchSlider& HatchSlider::GetInstance()
{
  static HatchSlider instance;
  return instance;
}

void HatchSlider::Set(State state)
{
  m_DSolenoid.Set(static_cast<frc::DoubleSolenoid::Value>(state));
  m_State = state;
}

HatchSlider::State HatchSlider::GetState()
{
  return m_State;
}

bool HatchSlider::IsExtended()
{
  return m_State == State::FORWARD;
}