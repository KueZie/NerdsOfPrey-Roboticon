/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
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

 public:
  Drivetrain();
  void InitDefaultCommand() override;
};
