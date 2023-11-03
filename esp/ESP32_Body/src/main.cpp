#include "main.h"

// #if !defined(MICRO_ROS_TRANSPORT_ARDUINO_SERIAL)
// #error This example is only avaliable for Arduino framework with serial transport.
// #endif

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;

void setup()
{
  Serial.begin(115200);

  Serial.println("Start Setup.");

  initMicroRos();
  initExecuterPub();
  initExecuterSub();

  setupAll();

  generatePublishers();
  addAllToExecutor();

  generateSubscribers();

  pinMode(PIN_LED_FORWARD, OUTPUT);
  digitalWrite(PIN_LED_FORWARD, LOW);
  
  Serial.println("finished setup");
}

void loop()
{
  delay(100);
  spinPub();
  spinSub();
}