#include "subsystems/Cargo.h"

Cargo* Cargo::m_Instance = nullptr;

Cargo::Cargo() : Subsystem("Cargo")
{
  m_Intake.reset( new WPI_VictorSPX(constants::cargo_intake::MOTOR_ID) );
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

void Cargo::InitDefaultCommand()
{
  SetDefaultCommand(new CargoOff());
}