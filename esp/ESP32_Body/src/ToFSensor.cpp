#include "ToFSensor.h"

ToFSensorTopicInfo m_oToFSensorTopicInfo;
VL53L1X tof_sensor;

void setupToFSensor()
{
    Serial.println(F("Initializing ToF Sensor..."));

    m_oToFSensorTopicInfo.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, ToFSensor);
    m_oToFSensorTopicInfo.msg.id = 0;

    tof_sensor.setTimeout(500);

    if (!tof_sensor.init())
    {
        Serial.println(F("Failed to boot VL53L1X"));
        while (1)
            ;
    }

    tof_sensor.setDistanceMode(VL53L1X::Long);
    tof_sensor.setMeasurementTimingBudget(50000);


    // start continuous ranging
    tof_sensor.startContinuous(50);

    Serial.println(F("ToF Sensor ready."));
}

void tofsensor_timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        tof_sensor.read();

        m_oToFSensorTopicInfo.msg.distance = tof_sensor.ranging_data.range_mm / 10;

        RCSOFTCHECK(rcl_publish(&(publishers[m_oToFSensorTopicInfo.publisherID]), &m_oToFSensorTopicInfo.msg, NULL));
    }
}
