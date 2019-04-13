/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class Cargo : public frc::Subsystem {
private:
  std::unique_ptr<VictorSPX> m_Intake;

public:
  Cargo();
  void In();
  void Out();
  void Off();
  void InitDefaultCommand() override;
};
