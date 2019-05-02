#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "Constants.h"
#include "commands/cargo/CargoOff.h"

class Cargo : public frc::Subsystem
{
private:
  WPI_VictorSPX m_Intake;
  Cargo();
public:
  static Cargo& GetInstance();
  ~Cargo() {}
  void In();
  void Out();
  void Off();
  virtual void InitDefaultCommand() override;
};
