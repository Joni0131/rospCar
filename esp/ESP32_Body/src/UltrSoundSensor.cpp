#include "UltrSoundSensor.h"

UltraSoundSensorTopicInfo m_oUltraSoundSensorTopicInfo;

void setupUltraSoundSensor() {
    Serial.println(F("Initializing Ultra Sound Sensor..."));

    m_oUltraSoundSensorTopicInfo.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, UltraSonicSensor);
    m_oUltraSoundSensorTopicInfo.msg.id = 0;

    Serial.println(F("Ultra Sound Sensor ready."));
}

void ultrasound_timer_callback(rcl_timer_t *timer, int64_t last_call_time) {
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        RCSOFTCHECK(rcl_publish(&(publishers[m_oUltraSoundSensorTopicInfo.publisherID]), &m_oUltraSoundSensorTopicInfo.msg, NULL));
    }
}
