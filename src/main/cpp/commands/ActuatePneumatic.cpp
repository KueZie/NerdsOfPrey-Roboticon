/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ActuatePneumatic.h"

ActuatePneumatic::ActuatePneumatic(frc::Subsystem* subsystem, SimplePneumaticSystem::State state)
  : m_State(state)
{
  Requires(subsystem);
  m_PneumaticsSystem = reinterpret_cast<SimplePneumaticSystem*>(subsystem);
}

void ActuatePneumatic::Initialize()
{
  m_PneumaticsSystem->Set(m_State);
}
