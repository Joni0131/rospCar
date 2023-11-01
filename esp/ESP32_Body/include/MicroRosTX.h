#ifndef MICROROSRX_H
#define MICROROSRX_H

#include "MicroRosMain.h"

#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int32.h>

extern rcl_allocator_t allocator;
extern rclc_support_t support;
extern rcl_node_t node;

extern rclc_executor_t executor_pub;

extern rcl_publisher_t publisher;
extern std_msgs__msg__Int32 current_PWM;
extern std_msgs__msg__Int32 msg;
extern rcl_timer_t timer;

void timer_callback(rcl_timer_t *timer, int64_t last_call_time);

void registerPublisher();

void initExecuterPub();

void createPublisher();

void createTimer();

void interimsPublishStart();


#endif