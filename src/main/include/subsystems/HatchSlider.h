#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <memory>
#include "Constants.h"
#include "util/SimplePneumaticSubsystem.h"

class HatchSlider : public SimplePneumaticSubsystem
{
private:
  std::unique_ptr<frc::DoubleSolenoid> m_DSolenoid;
  State m_State;

  static HatchSlider* m_Instance;
  HatchSlider();
public:
  static HatchSlider* GetInstance();
  ~HatchSlider() { delete m_Instance; }
  virtual void Set(State state) override;
  virtual State GetState() override;
  bool IsExtended();
};
