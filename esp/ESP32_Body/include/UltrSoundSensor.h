#ifndef ULTRASOUNDSENSOR_H
#define ULTRASOUNDSENSOR_H

#include <Arduino.h>
#include "TopicDefinitions.h"
#include "MicroRosMain.h"
#include "MicroRosTX.h"
#include "PinDefinitions.h"

extern UltraSoundSensorTopicInfo m_oUltraSoundSensorTopicInfo;
extern rcl_publisher_t publishers[MAX_PUBLISHER];

void setupUltraSoundSensor();

void ultrasound_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

#endif