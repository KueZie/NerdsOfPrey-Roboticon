/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RetractHatchSlider.h"

RetractHatchSlider::RetractHatchSlider() {
  Requires(HatchSlider::GetInstance());
}

// Called once when the command executes
void RetractHatchSlider::Initialize()
{
  HatchSlider::GetInstance()->In();
}
