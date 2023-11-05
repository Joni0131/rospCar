#ifndef STEERINGMOTOR_H
#define STEERINGMOTOR_H

#define SERVOINIT 100
#define SERVOMIN SERVOINIT-30
#define SERVOMAX SERVOINIT+30

#include <Arduino.h>
#include <ESP32Servo.h>
#include "TopicDefinitions.h"
#include "MicroRosMain.h"
#include "MicroRosRX.h"
#include "PinDefinitions.h"

extern rcl_publisher_t publishers[MAX_PUBLISHER];

extern Servo myservo;
extern ServoTopicInfo m_oServoTopicInfo;
extern ServoTopicTarget m_oServoTopicTarget;

void setupSteeringMotor();

void servo_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

void servo_subscriber_callback(const void *msgin);

#endif