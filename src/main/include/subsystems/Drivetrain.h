/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include <memory>
#include "Constants.h"
#include "util/Functions.h"
#include "commands/ArcadeDrive.h"
#include <iostream>

class Drivetrain : public frc::Subsystem {
private:
  // Master controllers
  std::unique_ptr<TalonSRX>  m_FrontLeftMotorMaster;
  std::unique_ptr<TalonSRX>  m_FrontRightMotorMaster;
  // Slave controllers
  std::unique_ptr<VictorSPX> m_MiddleLeftMotorSlave;
  std::unique_ptr<VictorSPX> m_MiddleRightMotorSlave;

  std::unique_ptr<VictorSPX> m_BackLeftMotorSlave;
  std::unique_ptr<VictorSPX> m_BackRightMotorSlave;

  // Gyro
  std::unique_ptr<AHRS> m_AHRS;

  static Drivetrain* m_Instance;

  Drivetrain(); // Prevent instantiation outside of this class
public:
  static Drivetrain* GetInstance();
  void Arcade(float throttle, float rotationSpeed);
  void Tank(float left, float right);
  float ResolveDeadband(float power);
  void ResetEncoderPositions();
  void ResetGyro();
  void ResetSensors();
  float GetYaw();
  float GetLeftEncoderPosition();
  float GetRightEncoderPosition();
  virtual void InitDefaultCommand() override;
  ~Drivetrain() { delete m_Instance; }
};
