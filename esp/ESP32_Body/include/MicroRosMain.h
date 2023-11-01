#ifndef MICROROSMAIN_H
#define MICROROSMAIN_H

#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>

#include "WifiDefinitions.h"

#define RCCHECK(fn)               \
  {                               \
    rcl_ret_t temp_rc = fn;       \
    if ((temp_rc != RCL_RET_OK))  \
    {                             \
      log_e("An error occured %d", fn); \
      error_loop();               \
    }                             \
  }
  
#define RCSOFTCHECK(fn)          \
  {                              \
    rcl_ret_t temp_rc = fn;      \
    if ((temp_rc != RCL_RET_OK)) \
    {                            \
    }                            \
  }

extern rcl_allocator_t allocator;
extern rclc_support_t support;
extern rcl_node_t node;

void initMicroRos();

void error_loop();

void createNode();

void createInitOptions();

void setupWifi();

void setupAllocator();

#endif