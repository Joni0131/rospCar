#ifndef ULTRASOUNDSENSOR_H
#define ULTRASOUNDSENSOR_H

#include <Arduino.h>
#include "PinDefinitions.h"
#include "NewPing.h"
#include "custom_interfaces/msg/ultra_sonic_sensor.h"

#define ULTRA_MAX_DISTANCE_CM 400

extern NewPing sonar;

void setupUltraSoundSensor(custom_interfaces__msg__UltraSonicSensor *ultraSoundMSG);

void ultrasound_callback(custom_interfaces__msg__UltraSonicSensor *ultraSoundMSG);

#endif