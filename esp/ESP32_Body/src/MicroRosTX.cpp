#include "MicroRosTX.h"

rclc_executor_t executor_pub;

rcl_publisher_t publisher;
std_msgs__msg__Int32 current_PWM;
std_msgs__msg__Int32 msg;
const char *motor_info_topic = "motor_info_topic";
rcl_timer_t timer;

void timer_callback(rcl_timer_t *timer, int64_t last_call_time) {
RCLC_UNUSED(last_call_time);
  if (timer != NULL)
  {
    RCSOFTCHECK(rcl_publish(&publisher, &current_PWM, NULL));
  }
}

void registerPublisher() {
    RCCHECK(rclc_executor_add_timer(&executor_pub, &timer));
}

void initExecuterPub() {
    RCCHECK(rclc_executor_init(&executor_pub, &support.context, 1, &allocator));
}

void createPublisher() {
    // create publisher
    RCCHECK(rclc_publisher_init_default(
        &publisher,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        motor_info_topic));
}

void createTimer() {
      // create timer,
  const unsigned int timer_timeout = 1000;
  RCCHECK(rclc_timer_init_default(
      &timer,
      &support,
      RCL_MS_TO_NS(timer_timeout),
      timer_callback));
}

void interimsPublishStart() {
    initExecuterPub();
    createPublisher();
    createTimer();
    registerPublisher();
}
