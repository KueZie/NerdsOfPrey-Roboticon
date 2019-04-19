/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Cargo.h"

Cargo::Cargo() : Subsystem("Cargo")
{
  m_Intake.reset( new VictorSPX(constants::cargo_intake::MOTOR_ID) );
  m_Intake->SetInverted(InvertType::None);
}

Cargo* Cargo::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new Cargo();
  return m_Instance;
}

void Cargo::In()
{
  m_Intake->Set(ControlMode::PercentOutput, -constants::cargo_intake::MAX_OUTPUT);
}

void Cargo::Out()
{
  m_Intake->Set(ControlMode::PercentOutput, constants::cargo_intake::MAX_OUTPUT);
}

void Cargo::Off()
{
  m_Intake->Set(ControlMode::PercentOutput, 0.0f);
}