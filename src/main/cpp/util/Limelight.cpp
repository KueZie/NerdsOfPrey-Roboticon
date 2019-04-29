#include "util/Limelight.h"

Limelight::Limelight(std::string name)
{
    m_LimelightTable = nt::NetworkTableInstance::GetDefault().GetTable(name);
}

bool Limelight::HasTarget()
{
    return static_cast<bool>(m_LimelightTable->GetNumber("tv", 0.0f));
}

void Limelight::SetLEDs(LED_MODE mode)
{
    m_LimelightTable->PutNumber("ledMode", static_cast<int>(mode));
}

void Limelight::SetPipeline(int slot)
{
    if (slot >= 0 && slot <= 9)
        m_LimelightTable->PutNumber("pipeline", slot);
}

void Limelight::SetCam(CAM_MODE mode)
{
    m_LimelightTable->PutNumber("camMode", static_cast<int>(mode));
}

double Limelight::GetDistanceFromTarget()
{
    using namespace constants::vision;

    return (VISION_TARGET_HEIGHT - limelight::DISTANCE_FROM_FLOOR) /
           std::tan(limelight::MOUNTING_ANGLE + GetVerticalOffsetFromTarget());
}

double Limelight::GetHorizontalOffsetFromTarget()
{
    return m_LimelightTable->GetNumber("tx", 0.0f);
}

double Limelight::GetVerticalOffsetFromTarget()
{
    return m_LimelightTable->GetNumber("ty", 0.0f);
}