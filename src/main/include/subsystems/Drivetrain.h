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

  Drivetrain* m_Instance;

  Drivetrain(); // Prevent instantiation outside of this class
public:
  Drivetrain* GetInstance();
  void ArcadeDrive(float throttle, float rotationSpeed);
  void TankDrive(float left, float right);
  ~Drivetrain() { delete m_Instance; }
};
