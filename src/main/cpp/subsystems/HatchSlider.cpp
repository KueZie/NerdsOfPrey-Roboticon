#include "subsystems/HatchSlider.h"

HatchSlider* HatchSlider::m_Instance = nullptr;

HatchSlider::HatchSlider() : Subsystem("ExampleSubsystem")
{
  m_DSolenoid.reset( new frc::DoubleSolenoid(constants::hatch_slider::SOLENOID_IDS[0], constants::hatch_slider::SOLENOID_IDS[1]) );
  // Start retracted
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
}

HatchSlider* HatchSlider::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new HatchSlider();
  return m_Instance;
}

void HatchSlider::Set(State state)
{
  m_DSolenoid->Set(static_cast<frc::DoubleSolenoid::Value>(state));
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