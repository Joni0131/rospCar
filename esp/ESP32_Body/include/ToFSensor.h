#ifndef TOFSENSOR_H
#define TOFSENSOR_H

#include <Arduino.h>
#include "TopicDefinitions.h"
#include "MicroRosMain.h"
#include "MicroRosTX.h"
#include "PinDefinitions.h"
#include <VL53L1X.h>

extern ToFSensorTopicInfo m_oToFSensorTopicInfo;
extern rcl_publisher_t publishers[MAX_PUBLISHER];
extern VL53L1X tof_sensor;

void setupToFSensor();

void tofsensor_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

#endif