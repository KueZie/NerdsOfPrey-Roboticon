/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

Drivetrain* Drivetrain::m_Instance = nullptr;

Drivetrain::Drivetrain() : Subsystem("Drivetrain")
{
  // Setup controllers
  m_FrontLeftMotorMaster.reset(  new TalonSRX(constants::drivetrain::left::FRONT_MOTOR_ID ) );
  m_FrontRightMotorMaster.reset( new TalonSRX(constants::drivetrain::right::FRONT_MOTOR_ID) );

  m_MiddleLeftMotorSlave.reset(  new VictorSPX(constants::drivetrain::left::MIDDLE_MOTOR_ID ) );
  m_MiddleRightMotorSlave.reset( new VictorSPX(constants::drivetrain::right::MIDDLE_MOTOR_ID) );

  m_BackLeftMotorSlave.reset(    new VictorSPX(constants::drivetrain::left::BACK_MOTOR_ID ) );
  m_BackRightMotorSlave.reset(   new VictorSPX(constants::drivetrain::right::BACK_MOTOR_ID) );

  m_AHRS.reset( new AHRS(SPI::Port::kMXP) );

  /*m_FrontLeftMotorMaster-> ConfigFactoryDefault();
  m_FrontRightMotorMaster->ConfigFactoryDefault();
  m_MiddleLeftMotorSlave-> ConfigFactoryDefault();
  m_MiddleRightMotorSlave->ConfigFactoryDefault();
  m_BackLeftMotorSlave->   ConfigFactoryDefault();
  m_BackRightMotorSlave->  ConfigFactoryDefault();*/

  m_FrontLeftMotorMaster-> ClearStickyFaults(constants::TIMEOUT_MS);
  m_FrontRightMotorMaster->ClearStickyFaults(constants::TIMEOUT_MS);
  m_MiddleLeftMotorSlave-> ClearStickyFaults(constants::TIMEOUT_MS);
  m_MiddleRightMotorSlave->ClearStickyFaults(constants::TIMEOUT_MS);
  m_BackLeftMotorSlave->   ClearStickyFaults(constants::TIMEOUT_MS);
  m_BackRightMotorSlave->  ClearStickyFaults(constants::TIMEOUT_MS);

  // Config master-slave
  /*m_MiddleLeftMotorSlave-> Follow(*m_FrontLeftMotorMaster);
  m_MiddleRightMotorSlave->Follow(*m_FrontRightMotorMaster);

  m_BackLeftMotorSlave-> Follow(*m_FrontLeftMotorMaster);
  m_BackRightMotorSlave->Follow(*m_FrontRightMotorMaster);*/

  // Setup encoders
  m_FrontLeftMotorMaster-> ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster-> SetSensorPhase(false);
  m_FrontRightMotorMaster->SetSensorPhase(false);

  // Setup motor inversions
  m_FrontLeftMotorMaster-> SetInverted(InvertType::None);
  m_FrontRightMotorMaster->SetInverted(InvertType::InvertMotorOutput);
  m_MiddleLeftMotorSlave-> SetInverted(InvertType::FollowMaster);
  m_MiddleRightMotorSlave->SetInverted(InvertType::FollowMaster);
  m_BackLeftMotorSlave->   SetInverted(InvertType::FollowMaster);
  m_BackRightMotorSlave->  SetInverted(InvertType::FollowMaster);

  m_FrontLeftMotorMaster-> SetNeutralMode(NeutralMode::Brake);
  m_FrontRightMotorMaster->SetNeutralMode(NeutralMode::Brake);
  m_MiddleLeftMotorSlave-> SetNeutralMode(NeutralMode::Brake);
  m_MiddleRightMotorSlave->SetNeutralMode(NeutralMode::Brake);
  m_BackLeftMotorSlave->   SetNeutralMode(NeutralMode::Brake);
  m_BackRightMotorSlave->  SetNeutralMode(NeutralMode::Brake);

  m_FrontLeftMotorMaster->ConfigNominalOutputForward(0.0f, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster->ConfigNominalOutputReverse(0.0f, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster->ConfigPeakOutputForward   (0.5f, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster->ConfigPeakOutputReverse   (0.5f, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster->ConfigOpenloopRamp(1, constants::TIMEOUT_MS);

  m_FrontRightMotorMaster->ConfigNominalOutputForward(0.0f, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster->ConfigNominalOutputReverse(0.0f, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster->ConfigPeakOutputForward   (0.5f, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster->ConfigPeakOutputReverse   (0.5f, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster->ConfigOpenloopRamp(1, constants::TIMEOUT_MS);
}

Drivetrain* Drivetrain::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new Drivetrain();
  return m_Instance;
}

float Drivetrain::ResolveDeadband(float power)
{
  if (abs(power) < constants::drivetrain::DEADBAND)
    return 0;
  return power;
}

void Drivetrain::Arcade(float throttle, float rotationSpeed)
{
  std::cout << "Running arcade..." << std::endl;
  float normalizedRotationSpeed = functions::clamp(rotationSpeed, -constants::drivetrain::MAX_TURN_SPEED, constants::drivetrain::MAX_TURN_SPEED);
  float normalizedThrottle = functions::clamp(throttle, -constants::drivetrain::MAX_THROTTLE, constants::drivetrain::MAX_THROTTLE);
  float left  = functions::normalize(throttle + rotationSpeed);
  float right = functions::normalize(throttle - rotationSpeed);
  Tank(left, right);
}

void Drivetrain::Tank(float left, float right)
{
  m_FrontLeftMotorMaster->Set(ControlMode::PercentOutput, ResolveDeadband( functions::normalize(left) ));
  m_FrontRightMotorMaster->Set(ControlMode::PercentOutput, ResolveDeadband( functions::normalize(right) ));
}

void Drivetrain::ResetEncoderPositions()
{
  m_FrontLeftMotorMaster-> SetSelectedSensorPosition(0, 0);
  m_FrontRightMotorMaster->SetSelectedSensorPosition(0, 0);
}

void Drivetrain::ResetGyro()
{
  m_AHRS->ZeroYaw();
}

void Drivetrain::ResetSensors()
{
  ResetEncoderPositions();
  ResetGyro();
}

float Drivetrain::GetYaw()
{
  return m_AHRS->GetYaw();
}

float Drivetrain::GetRightEncoderPosition()
{
  return m_FrontRightMotorMaster->GetSelectedSensorPosition(0);
}

float Drivetrain::GetLeftEncoderPosition()
{
  return m_FrontLeftMotorMaster->GetSelectedSensorPosition(0);
}

void Drivetrain::InitDefaultCommand()
{
  SetDefaultCommand(new ArcadeDrive());
}