#ifndef MICROROSSRV_H
#define MICROROSSRV_H

#include "MicroRosMain.h"

#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int32.h>
#include <custom_interfaces/srv/acceleromator_calibration.h> // Include your service

#include "GeneralDefinitions.h"

extern rcl_allocator_t allocator;
extern rclc_support_t support;
extern rcl_node_t node;

extern rclc_executor_t executor_srv; // Executor for services
extern rcl_service_t services[MAX_SERVICES]; // Array of services
extern custom_interfaces__srv__AcceleromatorCalibration_Request reqs[MAX_SERVICES]; // Array of request messages
extern custom_interfaces__srv__AcceleromatorCalibration_Response ress[MAX_SERVICES]; // Array of response messages

int registerService(const rosidl_service_type_support_t *type_support, const char *service_name, rclc_service_callback_t callback);

void initExecutorSrv();

void spinSrv();

void addAllServicesToExecutor();

#endif