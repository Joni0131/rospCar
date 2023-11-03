#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "TopicDefinitions.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "MicroRosMain.h"
#include "MicroRosRX.h"
#include "PinDefinitions.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif

extern AccelerometerTopic m_oAccelerromaterTopic;
extern std_msgs__msg__Int32 msg;
extern rcl_publisher_t publishers[MAX_PUBLISHER]; 

#define INITIALXGYRO 220
#define INITIALYGYRO 76
#define INITIALZGYRO -85
#define INITIALXACCEL 0
#define INITIALYACCEL 0
#define INITIALZACCEL 1788

void setupAccelerometer();

void accelerometer_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

#endif