#include "main.h"

// #if !defined(MICRO_ROS_TRANSPORT_ARDUINO_SERIAL)
// #error This example is only avaliable for Arduino framework with serial transport.
// #endif

void setup()
{
  Serial.begin(115200);

  Serial.println("Start Setup.");

  setupAll();

  generatePublishers();
  addAllToExecutor();

  generateSubscribers();

  Serial.println("finished setup");
}

void loop()
{
  spinPub();
  spinSub();
}