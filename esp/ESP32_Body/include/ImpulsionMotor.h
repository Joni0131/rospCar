#ifndef IMPULSIONMOTOR_H
#define IMPULSIONMOTOR_H

#define MAXIMPULSIONSPEED 255

#include <Arduino.h>
#include "TopicDefinitions.h"
#include "MicroRosMain.h"
#include "MicroRosRX.h"
#include "PinDefinitions.h"

extern rcl_publisher_t publishers[MAX_PUBLISHER];

extern ImpulsionTopicInfo m_oImpulsionTopicInfo;
extern ImpulsionTopicTarget m_oImpulsionTopicTarget;

void setupImpulsionMotor();

void impulsion_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

void impulsion_subscriber_callback(const void *msgin);

#endif