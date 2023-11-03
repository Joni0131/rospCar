#ifndef MICROROSRX_H
#define MICROROSRX_H

#include "MicroRosMain.h"

#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int32.h>

#include "GeneralDefinitions.h"

extern rcl_allocator_t allocator;
extern rclc_support_t support;
extern rcl_node_t node;

extern rclc_executor_t executor_pub;
extern rcl_publisher_t publishers[MAX_PUBLISHER];
extern rcl_timer_t timers[MAX_PUBLISHER];
extern std_msgs__msg__Int32 msg;

extern std_msgs__msg__Int32 current_PWM;

int registerPublisher(const rosidl_message_type_support_t *type_support, const char *topic_name, const unsigned int timer_timeout, rcl_timer_callback_t callback);

void initExecuterPub();

void interimsPublishStart();

void spinPub();

void addAllToExecutor();

#endif