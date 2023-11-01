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

  // put your setup code here, to run once:
  pinMode(PIN_LED_FORWARD, OUTPUT);
  pinMode(PIN_LED_BACKWARD, OUTPUT);
  pinMode(PIN_IMPULSION_ENABLE, OUTPUT);

  digitalWrite(PIN_LED_BACKWARD, LOW);
  digitalWrite(PIN_LED_FORWARD, LOW);
  digitalWrite(PIN_IMPULSION_ENABLE, HIGH);

  initMicroRos();

  interimsPublishStart();

  interStartupSubscribe();

  current_PWM.data = 0;
 
  Serial.println("finished setup");
}

void loop()
{
  delay(100);
  RCSOFTCHECK(rclc_executor_spin_some(&executor_pub, RCL_MS_TO_NS(100)));
  RCSOFTCHECK(rclc_executor_spin_some(&executor_sub, RCL_MS_TO_NS(100)));
  Serial.println(digitalRead(PIN_LED_BACKWARD));
}