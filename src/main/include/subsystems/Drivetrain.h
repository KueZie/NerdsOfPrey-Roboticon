/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
<<<<<<< HEAD
#include "ctre/Pheonix.h"
#include <AHRS.h>
#include <memory>

class Drivetrain : public frc::Subsystem {
  using left_drivetrain  = nop::constants::left_drivetrain;
  using right_drivetrain = nop::constants::right_drivetrain;
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  std::unique_ptr<TalonSRX> m_FrontLeftMotor  (new TalonSRX(left_drivetrain::FRONT_MOTOR_ID));
  std::unique_ptr<TalonSRX> m_MiddleLeftMotor (new TalonSRX(left_drivetrain::MIDDLE_MOTOR_ID));
  std::unique_ptr<TalonSRX> m_BackLeftMotor   (new TalonSRX(left_drivetrain::BACK_MOTOR_ID));
  std::unique_ptr<TalonSRX> m_FrontRightMotor (new TalonSRX(right_drivetrain::FRONT_MOTOR_ID));
  std::unique_ptr<TalonSRX> m_MiddleRightMotor(new TalonSRX(right_drivetrain::MIDDLE_MOTOR_ID));
  std::unique_ptr<TalonSRX> m_BackRightMotor  (new TalonSRX(right_drivetrain::BACK_MOTOR_ID));
  std::unique_ptr<AHRS>
=======
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include <memory>
#include "Constants.h"

class Drivetrain : public frc::Subsystem {
private:
  // Master controllers
  std::unique_ptr<TalonSRX>  m_FrontLeftMotorMaster;
  std::unique_ptr<TalonSRX>  m_FrontRightMotorMaster;
  // Slave controllers
  std::unique_ptr<VictorSPX> m_MiddleLeftMotorSlave;
  std::unique_ptr<VictorSPX> m_MiddleRightMotorSlave;
>>>>>>> be9dec72d3db26ead6eacbc815e4bc7a9fa714de

  std::unique_ptr<VictorSPX> m_BackLeftMotorSlave;
  std::unique_ptr<VictorSPX> m_BackRightMotorSlave;

  // Gyro
  std::unique_ptr<AHRS> m_AHRS;
public:
  Drivetrain();
  void InitDefaultCommand() override;
};
