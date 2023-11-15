
#include "EnvironmentDetection.h"

EnvironmentDetectionInfo m_oEnvironmentDetectionInfo;

void setupEnvironment()
{
    Serial.println(F("Initializing Environment Detection..."));

    m_oEnvironmentDetectionInfo.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, EnvironmentMeasurment);
    setupUltraSoundSensor(&m_oEnvironmentDetectionInfo.msg.ultrsound);
    setupToFSensor(&m_oEnvironmentDetectionInfo.msg.tofsensor);

    Serial.println(F("Environment Detection ready."));
}

void environment_timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        ultrasound_callback(&m_oEnvironmentDetectionInfo.msg.ultrsound);
        tofsensor_callback(&m_oEnvironmentDetectionInfo.msg.tofsensor);
        RCSOFTCHECK(rcl_publish(&(publishers[m_oEnvironmentDetectionInfo.publisherID]), &m_oEnvironmentDetectionInfo.msg, NULL));
    }
}