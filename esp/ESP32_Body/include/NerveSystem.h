#ifndef NERVESYSTEM_H
#define NERVESYSTEM_H

#include "TopicDefinitions.h"
#include "Accelerometer.h"
#include "MicroRosTX.h"
#include "SteeringMotor.h"
#include "ImpulsionMotor.h"
#include "EnvironmentDetection.h"

extern AccelerometerTopic m_oAccelerromaterTopic;
extern ServoTopicInfo m_oServoTopicInfo;
extern ServoTopicTarget m_oServoTopicTarget;
extern ImpulsionTopicInfo m_oImpulsionTopicInfo;
extern ImpulsionTopicTarget m_oImpulsionTopicTarget;
extern EnvironmentDetectionInfo m_oEnvironmentDetectionInfo;

void setupI2C();

void setupPWM();

void setupAll();

void generatePublishers();

void generateSubscribers();

#endif