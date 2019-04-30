#pragma once

#include <frc/commands/Subsystem.h>
#include <memory>
#include "util/Limelight.h"

class Vision : public frc::Subsystem
{
private:
  std::shared_ptr<Limelight> m_Limelight;
  static Vision* m_Instance;
public:
  Vision();
  static Vision* GetInstance();
  std::shared_ptr<Limelight> GetLimelight();
  void InitDefaultCommand() override;
};
