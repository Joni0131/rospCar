#include "ToFSensor.h"

ToFSensorTopicInfo m_oToFSensorTopicInfo;

void setupToFSensor() {
    Serial.println(F("Initializing ToF Sensor..."));

    m_oToFSensorTopicInfo.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, ToFSensor);
    m_oToFSensorTopicInfo.msg.id = 0;

    Serial.println(F("ToF Sensor ready."));
}

void tofsensor_timer_callback(rcl_timer_t *timer, int64_t last_call_time) {
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        RCSOFTCHECK(rcl_publish(&(publishers[m_oToFSensorTopicInfo.publisherID]), &m_oToFSensorTopicInfo.msg, NULL));
    }
}
