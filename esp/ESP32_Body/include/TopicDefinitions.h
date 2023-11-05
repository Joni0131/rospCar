#ifndef TOPICDEFINITIONS_H
#define TOPICDEFINITIONS_H

#include <Arduino.h>

#include "custom_interfaces/msg/acceleration_sensor.h"
#include "custom_interfaces/msg/servo_motor.h"
#include "custom_interfaces/msg/impulsion_motor.h"

typedef struct AccelerometerTopic {
    const char* publishTopic = "accelerometer_info";
    custom_interfaces__msg__AccelerationSensor msg;
    rosidl_message_type_support_t msg_type;
    const unsigned int timer_timeout = 10;
    int publisherID;
} AccelerometerTopic;

typedef struct ServoTopicInfo {
    const char* publishTopic = "servomotor_info";
    custom_interfaces__msg__ServoMotor msg;
    rosidl_message_type_support_t msg_type;
    const unsigned int timer_timeout = 100;
    int publisherID;
} ServoTopicInfo;

typedef struct ServoTopicTarget {
    const char* subscriberTopic = "servomotor_target";
    custom_interfaces__msg__ServoMotor msg;
    rosidl_message_type_support_t msg_type;
    const unsigned int timer_timeout = 100;
    int subscriberID;
} ServoTopicTarget;

typedef struct ImpulsionTopicInfo {
    const char* publishTopic = "impulsionmotor_info";
    custom_interfaces__msg__ImpulsionMotor msg;
    rosidl_message_type_support_t msg_type;
    const unsigned int timer_timeout = 100;
    int publisherID;
} ImpulsionTopicInfo;

typedef struct ImpulsionTopicTarget {
    const char* subscriberTopic = "impulsionmotor_target";
    custom_interfaces__msg__ImpulsionMotor msg;
    rosidl_message_type_support_t msg_type;
    const unsigned int timer_timeout = 100;
    int subscriberID;
} ImpulsionTopicTarget;

#endif