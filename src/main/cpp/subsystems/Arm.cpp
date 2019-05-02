#include "subsystems/Arm.h"

Arm::Arm()
  : Subsystem("Arm"),
    m_LeftMotorMaster(constants::arm::LEFT_MOTOR_ID), m_RightMotorSlave(constants::arm::RIGHT_MOTOR_ID)
{
  // m_LeftMotorMaster.ConfigFactoryDefault();
  // m_RightMotorSlave.ConfigFactoryDefault();

  // m_LeftMotorMaster.ConfigSelectedFeedbackSensor(motorcontrol::CTRE_MagEncoder_Relative);
  // m_RightMotorSlave.ConfigSelectedFeedbackSensor(motorcontrol::CTRE_MagEncoder_Relative);

  // m_RightMotorSlave.Follow(*m_LeftMotorMaster);

  // m_LeftMotorMaster.SetInverted(InvertType::None);
  // m_RightMotorSlave.SetInverted(InvertType::OpposeMaster);

  // m_LeftMotorMaster.SetNeutralMode(NeutralMode::Brake);
  // m_RightMotorSlave.SetNeutralMode(NeutralMode::Brake);

  // m_LeftMotorMaster.ConfigNominalOutputForward(0.0f, constants::TIMEOUT_MS);
  // m_LeftMotorMaster.ConfigNominalOutputReverse(0.0f, constants::TIMEOUT_MS);
  // m_LeftMotorMaster.ConfigPeakOutputForward(0.5f, constants::TIMEOUT_MS);
  // m_LeftMotorMaster.ConfigPeakOutputReverse(-0.5f, constants::TIMEOUT_MS);

  // m_LeftMotorMaster.Config_kP(0.0f, 0, constants::TIMEOUT_MS);
  // m_LeftMotorMaster.Config_kI(0.0f, 0, constants::TIMEOUT_MS);
  // m_LeftMotorMaster.Config_kD(0.0f, 0, constants::TIMEOUT_MS);
  // m_LeftMotorMaster.Config_kF(0.0f, 0, constants::TIMEOUT_MS);
  // m_LeftMotorMaster.SelectProfileSlot(0, 0);
  // m_LeftMotorMaster.ConfigMotionCruiseVelocity(1000.0f, constants::TIMEOUT_MS);
  // m_LeftMotorMaster.ConfigMotionAcceleration(1000.0f, constants::TIMEOUT_MS);
}

Arm& Arm::GetInstance()
{
  static Arm instance;
  return instance;
}

float Arm::GetEncoderPosition()
{
  return m_LeftMotorMaster.GetSelectedSensorPosition(0);
}

void Arm::ResetEncoderPosition()
{
  m_LeftMotorMaster.SetSelectedSensorPosition(0, 0, constants::TIMEOUT_MS);
}

void Arm::SetAngle(double angle)
{
  m_LeftMotorMaster.Set(ControlMode::MotionMagic, angle / constants::arm::ANGLE_CONVERSION_FACTOR);
}

float Arm::GetAngle()
{
  // Convert from native ticks to degrees
  return GetEncoderPosition() * constants::arm::ANGLE_CONVERSION_FACTOR;
}