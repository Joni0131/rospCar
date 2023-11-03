#ifndef NERVESYSTEM_H
#define NERVESYSTEM_H

#include "TopicDefinitions.h"
#include "Accelerometer.h"
#include "MicroRosTX.h"
#include "SteeringMotor.h"

extern AccelerometerTopic m_oAccelerromaterTopic;
extern ServoTopicInfo m_oServoTopicInfo;
extern ServoTopicTarget m_oServoTopicTarget;

void setupI2C();

void setupPWM();

void setupAll();

void generatePublishers();

void generateSubscribers();

#endif