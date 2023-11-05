#ifndef TOFSENSOR_H
#define TOFSENSOR_H

#include <Arduino.h>
#include "TopicDefinitions.h"
#include "MicroRosMain.h"
#include "MicroRosTX.h"
#include "PinDefinitions.h"

extern ToFSensorTopicInfo m_oToFSensorTopicInfo;
extern rcl_publisher_t publishers[MAX_PUBLISHER];

void setupToFSensor();

void tofsensor_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

#endif