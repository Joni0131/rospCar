#include "MicroRosRX.h"


rclc_executor_t executor_sub;

rcl_subscription_t subscriber;
const char *new_pwm_topic = "new_pwm_topic";


void subscription_callback(const void *msgin) {
    // Cast received message to used type
  const std_msgs__msg__Int32 *msg = (const std_msgs__msg__Int32 *)msgin;
  char buffer[40];
  sprintf(buffer, "Recieved: %d Current: %d", msg->data, current_PWM.data);
  Serial.println(buffer);
  if(msg->data %2){
    digitalWrite(PIN_LED, HIGH);
  }else{
    digitalWrite(PIN_LED, LOW);
  }
  current_PWM.data = msg->data;
  Serial.print("RECIEVED: ");
  Serial.println(current_PWM.data);
}

void registerSubscriber() {
    RCCHECK(rclc_executor_add_subscription(&executor_sub, &subscriber, &msg, &subscription_callback, ON_NEW_DATA));
}

void initExecuterSub() {
    RCCHECK(rclc_executor_init(&executor_sub, &support.context, 1, &allocator));
}

void createSubscriber() {
      // create subscriber
  RCCHECK(rclc_subscription_init_default(
      &subscriber,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
      new_pwm_topic));
}

void interStartupSubscribe(){
    initExecuterSub();
    createSubscriber();
    registerSubscriber();
}
