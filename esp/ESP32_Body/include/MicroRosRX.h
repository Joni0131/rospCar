#ifndef MICROROSTX_H
#define MICROROSTX_H

#include "MicroRosMain.h"

#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int32.h>

#include "PinDefinitions.h"

extern rcl_allocator_t allocator;
extern rclc_support_t support;
extern rcl_node_t node;

extern rclc_executor_t executor_sub;

extern rcl_subscription_t subscriber;
extern std_msgs__msg__Int32 msg;
extern std_msgs__msg__Int32 current_PWM;

void subscription_callback(const void *msgin);

void registerSubscriber();

void initExecuterSub();

void createSubscriber();

void interStartupSubscribe();

#endif