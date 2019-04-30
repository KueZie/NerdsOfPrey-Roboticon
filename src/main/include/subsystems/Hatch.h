#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <memory>
#include "Constants.h"
#include "util/SimplePneumaticSystem.h"

class Hatch : public frc::Subsystem, public SimplePneumaticSystem
{
private:
  std::unique_ptr<frc::DoubleSolenoid> m_DSolenoid;
  State m_State;

  static Hatch* m_Instance;
  Hatch();
public:
  static Hatch* GetInstance();
  ~Hatch() { delete m_Instance; }
  virtual void Set(State state) override;
  virtual State GetState() override;
  bool IsGrabbing();
};
