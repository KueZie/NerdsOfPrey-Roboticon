/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/HatchSlider.h"

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
m_DSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
}

void HatchSlider::In()
{
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
}

void HatchSlider::Off()
{
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kOff);
}