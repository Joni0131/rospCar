#ifndef ULTRASOUNDSENSOR_H
#define ULTRASOUNDSENSOR_H

#include <Arduino.h>
#include "TopicDefinitions.h"
#include "MicroRosMain.h"
#include "MicroRosTX.h"
#include "PinDefinitions.h"
#include "NewPing.h"

#define ULTRA_MAX_DISTANCE_CM 400

extern UltraSoundSensorTopicInfo m_oUltraSoundSensorTopicInfo;
extern rcl_publisher_t publishers[MAX_PUBLISHER];
extern NewPing sonar;

void setupUltraSoundSensor();

void ultrasound_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

#endif