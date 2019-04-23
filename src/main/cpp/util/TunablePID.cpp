#include "util/TunablePID.h"

TunablePID::TunablePID(double kF, double kP, double kI, double kD)
    : m_kF(kF), m_kP(kP), m_kI(kI), m_kD(kD)
{}