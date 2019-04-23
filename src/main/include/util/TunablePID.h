#pragma once

class TunablePID
{
public:
    TunablePID(double kF, double kP, double kI, double kD);
    ~TunablePID();
private:
    double m_kF, m_kP, m_kI, m_kD;
};