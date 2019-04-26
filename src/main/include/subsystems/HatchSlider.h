#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <memory>
#include "Constants.h"

class HatchSlider : public frc::Subsystem {
private:
  std::unique_ptr<frc::DoubleSolenoid> m_DSolenoid;
  bool m_IsOut = false;

  static HatchSlider* m_Instance;
  HatchSlider();
public:
  static HatchSlider* GetInstance();
  ~HatchSlider() { delete m_Instance; }
  void Out();
  void In();
  void Toggle();
  void Off();
  bool IsExtended();
};
