#ifndef TOFSENSOR_H
#define TOFSENSOR_H

#include <Arduino.h>
#include "PinDefinitions.h"
#include <VL53L1X.h>
#include "custom_interfaces/msg/to_f_sensor.h"

extern VL53L1X tof_sensor;

void setupToFSensor(custom_interfaces__msg__ToFSensor *toFSensorMSG);

void tofsensor_callback(custom_interfaces__msg__ToFSensor *toFSensorMSG);

#endif