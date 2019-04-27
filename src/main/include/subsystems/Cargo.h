#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "Constants.h"
#include "commands/cargo/CargoOff.h"

class Cargo : public frc::Subsystem {
private:
  std::unique_ptr<VictorSPX> m_Intake;
  static Cargo* m_Instance;
  Cargo();
public:
  static Cargo* GetInstance();
  ~Cargo() { delete m_Instance; }
  void In();
  void Out();
  void Off();
  virtual void InitDefaultCommand() override;
};
