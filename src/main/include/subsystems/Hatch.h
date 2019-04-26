#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <memory>
#include "Constants.h"

class Hatch : public frc::Subsystem {
private:
  std::unique_ptr<frc::DoubleSolenoid> m_DSolenoid;
  bool m_IsGrabbing = true; // Start with hatch grabbed

  static Hatch* m_Instance;
  Hatch();
public:
  static Hatch* GetInstance();
  ~Hatch() { delete m_Instance; }
  void Grab();
  void Release();
  void Toggle();
  void Off();
  bool IsGrabbing();
};
