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

#define INITIALXGYRO 31
#define INITIALYGYRO 3
#define INITIALZGYRO 14
#define INITIALXACCEL -2285
#define INITIALYACCEL -5011
#define INITIALZACCEL 4867
#define ACCEL_LSB 8192
#define GYROS_LSB 131

void setupAccelerometer();

void accelerometer_timer_callback(rcl_timer_t *timer, int64_t last_call_time);

void caliberAccelerometer();

#endif