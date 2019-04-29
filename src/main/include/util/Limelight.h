#pragma once

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <string>
#include <memory>
#include <cmath>

#include "util/Functions.h"
#include "Constants.h"

class Limelight
{
public:
    enum class LED_MODE { PIPELINE, OFF, BLINK, ON };
    enum class CAM_MODE { VISION_PROCESSING, DRIVE_CAMERA };
    Limelight(std::string name);
    Limelight() {}
    ~Limelight() {}
    bool HasTarget();
    bool IsConnected();
    void SetLEDs(LED_MODE mode);
    void SetPipeline(int slot);
    void SetCam(CAM_MODE mode);
    double GetDistanceFromTarget();
    double GetHorizontalOffsetFromTarget();
    double GetVerticalOffsetFromTarget();
private:
    std::shared_ptr<NetworkTable> m_LimelightTable;
};