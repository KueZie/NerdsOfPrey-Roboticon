#include "subsystems/Drivetrain.h"

Drivetrain::Drivetrain()
  : Subsystem("Drivetrain"), 
    m_FrontLeftMotorMaster(constants::drivetrain::left::FRONT_MOTOR_ID ), m_FrontRightMotorMaster(constants::drivetrain::right::FRONT_MOTOR_ID) ,
    m_MiddleLeftMotorSlave(constants::drivetrain::left::MIDDLE_MOTOR_ID), m_MiddleRightMotorSlave(constants::drivetrain::right::MIDDLE_MOTOR_ID),
    m_BackLeftMotorSlave  (constants::drivetrain::left::BACK_MOTOR_ID  ), m_BackRightMotorSlave  (constants::drivetrain::right::BACK_MOTOR_ID  ),
    m_AHRS(SPI::Port::kMXP)
{
  /*m_FrontLeftMotorMaster.ConfigFactoryDefault();
  m_FrontRightMotorMaster .ConfigFactoryDefault();
  m_MiddleLeftMotorSlave  .ConfigFactoryDefault();
  m_MiddleRightMotorSlave .ConfigFactoryDefault();
  m_BackLeftMotorSlave    .ConfigFactoryDefault();
  m_BackRightMotorSlave   .ConfigFactoryDefault();*/

  // Config master-slave
  /*m_MiddleLeftMotorSlave.Follow(*m_FrontLeftMotorMaster);
  m_MiddleRightMotorSlave .Follow(*m_FrontRightMotorMaster);

  m_BackLeftMotorSlave .Follow(*m_FrontLeftMotorMaster);
  m_BackRightMotorSlave.Follow(*m_FrontRightMotorMaster);*/

  // Setup encoders
  m_FrontLeftMotorMaster .ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster .SetSensorPhase(false);
  m_FrontRightMotorMaster.SetSensorPhase(false);

  // Setup motor inversions
  m_FrontLeftMotorMaster    .SetInverted(InvertType::None);
  m_FrontRightMotorMaster   .SetInverted(InvertType::InvertMotorOutput);
  // m_MiddleLeftMotorSlave .SetInverted(InvertType::FollowMaster);
  // m_MiddleRightMotorSlave.SetInverted(InvertType::FollowMaster);
  // m_BackLeftMotorSlave   .SetInverted(InvertType::FollowMaster);
  // m_BackRightMotorSlave  .SetInverted(InvertType::FollowMaster);

  m_FrontLeftMotorMaster    .SetNeutralMode(NeutralMode::Brake);
  m_FrontRightMotorMaster   .SetNeutralMode(NeutralMode::Brake);
  // m_MiddleLeftMotorSlave .SetNeutralMode(NeutralMode::Brake);
  // m_MiddleRightMotorSlave.SetNeutralMode(NeutralMode::Brake);
  // m_BackLeftMotorSlave   .SetNeutralMode(NeutralMode::Brake);
  // m_BackRightMotorSlave  .SetNeutralMode(NeutralMode::Brake);

  // m_FrontLeftMotorMaster .ClearStickyFaults(constants::TIMEOUT_MS);
  // m_FrontRightMotorMaster.ClearStickyFaults(constants::TIMEOUT_MS);
  // m_MiddleLeftMotorSlave .ClearStickyFaults(constants::TIMEOUT_MS);
  // m_MiddleRightMotorSlave.ClearStickyFaults(constants::TIMEOUT_MS);
  // m_BackLeftMotorSlave   .ClearStickyFaults(constants::TIMEOUT_MS);
  // m_BackRightMotorSlave  .ClearStickyFaults(constants::TIMEOUT_MS);

  m_FrontLeftMotorMaster.ConfigNominalOutputForward(0.0f, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster.ConfigNominalOutputReverse(0.0f, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster.ConfigPeakOutputForward   (0.5f, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster.ConfigPeakOutputReverse   (-0.5f, constants::TIMEOUT_MS);
  m_FrontLeftMotorMaster.ConfigOpenloopRamp(0.5f, constants::TIMEOUT_MS);
  
  m_FrontRightMotorMaster.ConfigNominalOutputForward(0.0f, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster.ConfigNominalOutputReverse(0.0f, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster.ConfigPeakOutputForward   (0.5f, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster.ConfigPeakOutputReverse   (-0.5f, constants::TIMEOUT_MS);
  m_FrontRightMotorMaster.ConfigOpenloopRamp(0.5f, constants::TIMEOUT_MS);

  ResetSensors();
}

Drivetrain& Drivetrain::GetInstance()
{
  static Drivetrain instance;
  return instance;
}

float Drivetrain::ResolveDeadband(float power)
{
  if (abs(power) < constants::drivetrain::DEADBAND)
    return 0;
  return power;
}

void Drivetrain::Arcade(float throttle, float rotationSpeed)
{
  std::cout << "Running arcade..." << std::endl;

  // float normalizedRotationSpeed = functions::clamp(rotationSpeed, -constants::drivetrain::MAX_TURN_SPEED, constants::drivetrain::MAX_TURN_SPEED);
  // float normalizedThrottle = functions::clamp(throttle, -constants::drivetrain::MAX_THROTTLE, constants::drivetrain::MAX_THROTTLE);

  float left  = functions::normalize(throttle - rotationSpeed);
  float right = functions::normalize(throttle + rotationSpeed);

  Tank(left, right);
}

void Drivetrain::Tank(float left, float right)
{
  double leftPower  = ResolveDeadband( functions::normalize(left) );
  double rightPower = ResolveDeadband( functions::normalize(right) );

  std::cout << "SetPower(" << leftPower << ", " << rightPower << ")\n";

  m_FrontLeftMotorMaster .Set(ControlMode::PercentOutput, leftPower);
  m_FrontRightMotorMaster.Set(ControlMode::PercentOutput, rightPower);
  
  std::cout << "TankPower(" << GetLeftPercentOutput() << ", " << GetRightPercentOutput() << ")\n";
}

void Drivetrain::Curvature(float throttle, float wheel)
{
  double wheelNonLinearity = 0.5f;
  wheel = ResolveDeadband(wheel);
  throttle = ResolveDeadband(throttle);
  float sensitivity = constants::drivetrain::SENSITIVITY;

  double negativeInertia = wheel - m_OldWheel;
  m_OldWheel = wheel;
  for (int i = 0; i < 3; ++i)
    wheel = CurvatureSinScalar(wheelNonLinearity, wheel);

  double leftPWM, rightPWM, overPower;
  double angularPower;
  double linearPower;
  // Negative inertia!
  double negativeInertiaAccumulator = 0.0;
  double negativeInertiaScalar;

  if (wheel * negativeInertia < 0)
    negativeInertiaScalar = 2.5f;
  else
    if (fabs(wheel) > 0.65)
      negativeInertiaScalar = 5.0f;
    else
      negativeInertiaScalar = 3.0f;
  double negativeInertiaPower = negativeInertia * negativeInertiaScalar;
  negativeInertiaAccumulator += negativeInertiaPower;

  wheel = wheel + negativeInertiaPower;
  if (negativeInertiaAccumulator > 1)
    negativeInertiaAccumulator -= 1;
  else if (negativeInertiaAccumulator > -1)
    negativeInertiaAccumulator += 1;
  else
    negativeInertiaAccumulator = 0;

  linearPower = throttle;
  
  if (m_IsQuickTurn)
  {
    if (abs(throttle) < 0.2f)
    {
      double alpha = 0.1;
      m_QuickStopAccumulator = (1 - alpha) * m_QuickStopAccumulator + alpha * functions::clamp(wheel, -1, 1);
    }
    overPower = 1.0f;
    sensitivity = 1.0f;
    angularPower = wheel;
  }
  else
  {
    overPower = 0.0f;
    angularPower = abs(throttle) * wheel * sensitivity - m_QuickStopAccumulator;
    if (m_QuickStopAccumulator > 1) {
        m_QuickStopAccumulator -= 1;
      } else if (m_QuickStopAccumulator < -1) {
        m_QuickStopAccumulator += 1;
      } else {
        m_QuickStopAccumulator = 0.0;
      }
  }

  rightPWM = linearPower - angularPower;
  leftPWM = linearPower + angularPower;

  if (leftPWM > 1.0) {
    rightPWM -= overPower * (leftPWM - 1.0);
    leftPWM = 1.0;
  } 
  else if (rightPWM > 1.0) 
  {
    leftPWM -= overPower * (rightPWM - 1.0);
    rightPWM = 1.0;
  }
  else if (leftPWM < -1.0) 
  {
    rightPWM += overPower * (-1.0 - leftPWM);
    leftPWM = -1.0;
  } 
  else if (rightPWM < -1.0) 
  {
    leftPWM += overPower * (-1.0 - rightPWM);
    rightPWM = -1.0;
  }
  std::cout << "SetPower(" << leftPWM << ", " << rightPWM << ")\n";
  Tank(leftPWM, rightPWM);
}

double Drivetrain::CurvatureSinScalar(double wheelNonLinearity, double wheel)
{
  return sin(constants::PI / 2.0 * wheelNonLinearity * wheel) / sin(constants::PI / 2.0 * wheelNonLinearity);
}

void Drivetrain::ResetEncoderPositions()
{
  m_FrontLeftMotorMaster .SetSelectedSensorPosition(0, 0);
  m_FrontRightMotorMaster.SetSelectedSensorPosition(0, 0);
}

void Drivetrain::ResetGyro()
{
  m_AHRS.ZeroYaw();
}

void Drivetrain::ResetSensors()
{
  ResetEncoderPositions();
  ResetGyro();
}

float Drivetrain::GetYaw()
{
  return m_AHRS.GetYaw();
}

float Drivetrain::GetRightEncoderPosition()
{
  return m_FrontRightMotorMaster.GetSelectedSensorPosition(0);
}

float Drivetrain::GetLeftEncoderPosition()
{
  return m_FrontLeftMotorMaster.GetSelectedSensorPosition(0);
}

float Drivetrain::GetLeftPercentOutput()
{
  return m_FrontLeftMotorMaster.GetMotorOutputPercent();
}

float Drivetrain::GetRightPercentOutput()
{
  return m_FrontRightMotorMaster.GetMotorOutputPercent();
}

void Drivetrain::InitDefaultCommand()
{
  SetDefaultCommand(new ArcadeDrive());
}

void Drivetrain::SetQuickTurn(bool quickTurn)
{
  m_IsQuickTurn = quickTurn;
}
bool Drivetrain::IsQuickTurn()
{
  return m_IsQuickTurn;
}