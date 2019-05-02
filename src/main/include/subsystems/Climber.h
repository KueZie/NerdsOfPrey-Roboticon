#pragma once

#include <frc/commands/Subsystem.h>

class Climber : public frc::Subsystem
{
private:
  Climber();
public:
  static Climber& GetInstance();
};
