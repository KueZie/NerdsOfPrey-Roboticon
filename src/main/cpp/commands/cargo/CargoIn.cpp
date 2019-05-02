#include "commands/cargo/CargoIn.h"

CargoIn::CargoIn()
{
  Requires(&Cargo::GetInstance());
}

void CargoIn::Initialize() 
{
  Cargo::GetInstance().In();
}
