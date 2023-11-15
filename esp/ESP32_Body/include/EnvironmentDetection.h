#ifndef ENVIRONMENTDETECTION_H
#define ENVIRONMENTDETECTION_H

#include <Arduino.h>
#include "TopicDefinitions.h"
#include "MicroRosMain.h"
#include "MicroRosTX.h"
#include "UltrSoundSensor.h"
#include "ToFSensor.h"

extern EnvironmentDetectionInfo m_oEnvironmentDetectionInfo;

void setupEnvironment();

void environment_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

#endif