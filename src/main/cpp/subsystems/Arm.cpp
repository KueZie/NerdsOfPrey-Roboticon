/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Arm.h"

Arm* Arm::m_Instance = nullptr;

Arm::Arm() : Subsystem("Arm")
{
  m_LeftMotorMaster.reset( new TalonSRX(constants::arm::LEFT_MOTOR_ID) );
  m_RightMotorSlave.reset( new VictorSPX(constants::arm::RIGHT_MOTOR_ID) );

  m_LeftMotorMaster->ConfigFactoryDefault();
  m_RightMotorSlave->ConfigFactoryDefault();

  m_LeftMotorMaster->ConfigSelectedFeedbackSensor(motorcontrol::CTRE_MagEncoder_Relative);
  m_RightMotorSlave->ConfigSelectedFeedbackSensor(motorcontrol::CTRE_MagEncoder_Relative);

  m_RightMotorSlave->Follow(*m_LeftMotorMaster);

  m_LeftMotorMaster->SetInverted(InvertType::None);
  m_RightMotorSlave->SetInverted(InvertType::OpposeMaster);

  m_LeftMotorMaster->SetNeutralMode(NeutralMode::Brake);
  m_RightMotorSlave->SetNeutralMode(NeutralMode::Brake);

  m_LeftMotorMaster->ConfigNominalOutputForward(0.0f, constants::TIMEOUT_MS);
  m_LeftMotorMaster->ConfigNominalOutputReverse(0.0f, constants::TIMEOUT_MS);
  m_LeftMotorMaster->ConfigPeakOutputForward(0.5f, constants::TIMEOUT_MS);
  m_LeftMotorMaster->ConfigPeakOutputReverse(0.5f, constants::TIMEOUT_MS);

  m_LeftMotorMaster->Config_kP(0.0f, 0, constants::TIMEOUT_MS);
  m_LeftMotorMaster->Config_kI(0.0f, 0, constants::TIMEOUT_MS);
  m_LeftMotorMaster->Config_kD(0.0f, 0, constants::TIMEOUT_MS);
  m_LeftMotorMaster->Config_kF(0.0f, 0, constants::TIMEOUT_MS);
  m_LeftMotorMaster->SelectProfileSlot(0, 0);
  m_LeftMotorMaster->ConfigMotionCruiseVelocity(1000.0f, constants::TIMEOUT_MS);
  m_LeftMotorMaster->ConfigMotionAcceleration(1000.0f, constants::TIMEOUT_MS);
}

Arm* Arm::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new Arm();
  return m_Instance;
}

float Arm::GetEncoderPosition()
{
  return m_LeftMotorMaster->GetSelectedSensorPosition(0);
}

void Arm::ResetEncoderPosition()
{
  m_LeftMotorMaster->SetSelectedSensorPosition(0, 0, constants::TIMEOUT_MS);
}

void Arm::SetAngle(double angle)
{
  // m_LeftMotorMaster->Set(ControlMode::MotionMagic, angl);
}

float Arm::GetAngle()
{
  return GetEncoderPosition() * constants::arm::ANGLE_CONVERSION_FACTOR;
}