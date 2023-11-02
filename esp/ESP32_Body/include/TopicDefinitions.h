#ifndef TOPICDEFINITIONS_H
#define TOPICDEFINITIONS_H

#include <Arduino.h>

#include "custom_interfaces/msg/acceleration_sensor.h"

typedef struct AccelerometerTopic {
    const char* publishTopic = "accelerometer_info";
    custom_interfaces__msg__AccelerationSensor msg;
    rosidl_message_type_support_t msg_type;
    const unsigned int timer_timeout = 1000;
    int publisherID;
} AccelerometerTopic;

#endif