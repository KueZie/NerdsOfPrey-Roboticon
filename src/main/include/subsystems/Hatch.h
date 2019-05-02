#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <memory>
#include "Constants.h"
#include "util/SimplePneumaticSubsystem.h"

class Hatch : public SimplePneumaticSubsystem
{
private:
  frc::DoubleSolenoid m_DSolenoid;
  State m_State;

  Hatch();
public:
  static Hatch& GetInstance();
  ~Hatch() {}
  virtual void Set(State state) override;
  virtual State GetState() override;
  bool IsGrabbing();
};
