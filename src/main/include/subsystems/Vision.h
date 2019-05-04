#pragma once

#include <frc/commands/Subsystem.h>
#include "util/Limelight.h"

class Vision : public frc::Subsystem
{
private:
  Limelight m_Limelight;
public:
  Vision();
  static Vision& GetInstance();
  Limelight& GetLimelight();
  void InitDefaultCommand() override;
};
