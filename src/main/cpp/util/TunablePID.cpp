#include "util/TunablePID.h"

TunablePID::TunablePID(double kF, double kP, double kI, double kD, double dt)
    : m_kF(kF), m_kP(kP), m_kI(kI), m_kD(kD), m_TimeStep(dt)
{}

void TunablePID::SetConstraints(double min, double max)
{
    if (min == max)
        throw "Given minimum and maximum cannot be equal.";
    if (min > max)
        throw "Given minimum is greater than the maximum.";
    m_Min = min;
    m_Max = max;
}

void TunablePID::SetTarget(double target)
{
    if (target > m_Max)
        throw TargetOutOfRange();
    else if (target < m_Min)
        throw TargetOutOfRange();
    
    m_Target = target;
}