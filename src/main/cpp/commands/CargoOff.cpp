#include "commands/CargoOff.h"

CargoOff::CargoOff() {
  Requires(Cargo::GetInstance());
}

void CargoOff::Initialize()
{
  Cargo::GetInstance()->Off();
}
