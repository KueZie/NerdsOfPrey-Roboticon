#include "commands/CargoIn.h"

CargoIn::CargoIn() {
  Requires(Cargo::GetInstance());
}

void CargoIn::Initialize() 
{
  Cargo::GetInstance()->In();
}
