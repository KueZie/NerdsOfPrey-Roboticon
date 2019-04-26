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

void HatchSlider::Out()
{
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
  m_IsOut = true;
}

void HatchSlider::In()
{
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
  m_IsOut = false;
}

void HatchSlider::Toggle()
{
  m_IsOut = !m_IsOut;
  if (m_IsOut) Out();
  else In();
}

void HatchSlider::Off()
{
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kOff);
}

bool HatchSlider::IsExtended()
{
  return m_IsOut;
}