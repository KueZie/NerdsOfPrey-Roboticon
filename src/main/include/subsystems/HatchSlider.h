#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include "Constants.h"
#include "util/SimplePneumaticSubsystem.h"

class HatchSlider : public SimplePneumaticSubsystem
{
private:
  frc::DoubleSolenoid m_DSolenoid;
  State m_State;

  HatchSlider();
public:
  static HatchSlider& GetInstance();
  ~HatchSlider() {}
  virtual void Set(State state) override;
  virtual State GetState() override;
  bool IsExtended();
};
