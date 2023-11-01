#include "main.h"

// #if !defined(MICRO_ROS_TRANSPORT_ARDUINO_SERIAL)
// #error This example is only avaliable for Arduino framework with serial transport.
// #endif





// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;

void subscription_callback(const void *msgin)
{
  
}

void setup()
{
  Serial.begin(115200);
  
  initMicroRos();

  interimsPublishStart();

  interStartupSubscribe();

  current_PWM.data = 0;
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  Serial.println("finished setup");
}

void loop()
{
  delay(100);
  RCSOFTCHECK(rclc_executor_spin_some(&executor_pub, RCL_MS_TO_NS(100)));
  RCSOFTCHECK(rclc_executor_spin_some(&executor_sub, RCL_MS_TO_NS(100)));
}