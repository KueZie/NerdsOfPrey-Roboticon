/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain")
{
  // Setup controllers
  m_FrontLeftMotorMaster.reset(  new TalonSRX(constants::drivetrain::left::FRONT_MOTOR_ID ) );
  m_FrontRightMotorMaster.reset( new TalonSRX(constants::drivetrain::right::FRONT_MOTOR_ID) );

  m_MiddleLeftMotorSlave.reset(  new VictorSPX(constants::drivetrain::left::MIDDLE_MOTOR_ID ) );
  m_MiddleRightMotorSlave.reset( new VictorSPX(constants::drivetrain::right::MIDDLE_MOTOR_ID) );

  m_BackLeftMotorSlave.reset(    new VictorSPX(constants::drivetrain::left::BACK_MOTOR_ID ) );
  m_BackRightMotorSlave.reset(   new VictorSPX(constants::drivetrain::right::BACK_MOTOR_ID) );

  m_FrontLeftMotorMaster-> ConfigFactoryDefault();
  m_FrontRightMotorMaster->ConfigFactoryDefault();
  m_MiddleLeftMotorSlave-> ConfigFactoryDefault();
  m_MiddleRightMotorSlave->ConfigFactoryDefault();
  m_BackLeftMotorSlave->   ConfigFactoryDefault();
  m_BackRightMotorSlave->  ConfigFactoryDefault();

  // Config master-slave
  m_MiddleLeftMotorSlave-> Follow(*m_FrontLeftMotorMaster.get());
  m_MiddleRightMotorSlave->Follow(*m_FrontRightMotorMaster.get());

  m_BackLeftMotorSlave-> Follow(*m_FrontLeftMotorMaster.get());
  m_BackRightMotorSlave->Follow(*m_FrontRightMotorMaster.get());

  // Setup encoders
  m_FrontLeftMotorMaster-> ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
  m_FrontRightMotorMaster->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
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

  m_FrontLeftMotorMaster->ConfigNominalOutputForward(0.0f, constants::timeout);
  m_FrontLeftMotorMaster->ConfigNominalOutputReverse(0.0f, constants::timeout);
  m_FrontLeftMotorMaster->ConfigPeakOutputForward   (0.5f, constants::timeout);
  m_FrontLeftMotorMaster->ConfigPeakOutputReverse   (0.5f, constants::timeout);
  m_FrontLeftMotorMaster->ConfigOpenloopRamp(1, constants::timeout);

  m_FrontRightMotorMaster->ConfigNominalOutputForward(0.0f, constants::timeout);
  m_FrontRightMotorMaster->ConfigNominalOutputReverse(0.0f, constants::timeout);
  m_FrontRightMotorMaster->ConfigPeakOutputForward   (0.5f, constants::timeout);
  m_FrontRightMotorMaster->ConfigPeakOutputReverse   (0.5f, constants::timeout);
  m_FrontRightMotorMaster->ConfigOpenloopRamp(1, constants::timeout);
}

void Drivetrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
