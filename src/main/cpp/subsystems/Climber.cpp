/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"

Climber* Climber::m_Instance = nullptr;

Climber::Climber() : Subsystem("ExampleSubsystem")
{}

Climber* Climber::GetInstance()
{
  if (m_Instance == nullptr)
    m_Instance = new Climber();
  return m_Instance;
}
