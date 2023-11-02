#ifndef NERVESYSTEM_H
#define NERVESYSTEM_H

#include "TopicDefinitions.h"
#include "Accelerometer.h"
#include "MicroRosTX.h"

extern AccelerometerTopic m_oAccelerromaterTopic;

void setupI2C();

void setupAll();

void generatePublishers();

void generateSubscribers();

#endif