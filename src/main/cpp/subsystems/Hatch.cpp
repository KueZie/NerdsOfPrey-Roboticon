/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Hatch.h"

Hatch* Hatch::m_Instance = nullptr;

Hatch::Hatch() : Subsystem("Hatch")
{
  m_DSolenoid.reset( new frc::DoubleSolenoid(constants::hatch_intake::SOLENOID_IDS[0], constants::hatch_intake::SOLENOID_IDS[1]) );
  // Start retracted
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
}

Hatch* Hatch::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new Hatch();
  return m_Instance;
}

void Hatch::Grab()
{
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
  m_IsGrabbing = true;
}

void Hatch::Release()
{
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
  m_IsGrabbing = false;
}

void Hatch::Toggle()
{
  m_IsGrabbing = !m_IsGrabbing;
  if (m_IsGrabbing) Grab();
  else Release();
}

void Hatch::Off()
{
  m_DSolenoid->Set(frc::DoubleSolenoid::Value::kOff);
}