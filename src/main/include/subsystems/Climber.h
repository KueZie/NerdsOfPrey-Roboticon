#pragma once

#include <frc/commands/Subsystem.h>

class Climber : public frc::Subsystem
{
private:
  static Climber* m_Instance;
  Climber();
public:
  static Climber* GetInstance();
};
