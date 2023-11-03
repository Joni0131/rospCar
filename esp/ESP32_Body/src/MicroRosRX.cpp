#include "MicroRosRX.h"

rclc_executor_t executor_sub;
rcl_subscription_t subscribers[MAX_SUBSCRIBER];

int currentNumberSub = 0;

const char *new_pwm_topic = "new_pwm_topic";

void createSubscriber(rcl_subscription_t *subscriber, const rosidl_message_type_support_t *type_support, const char *topic_name)
{
  // create subscriber
  RCCHECK(rclc_subscription_init_default(
      subscriber,
      &node,
      type_support,
      topic_name));
}

int registerSubscriber(const rosidl_message_type_support_t *type_support, const char *topic_name, void *msg, rclc_subscription_callback_t callback, rclc_executor_handle_invocation_t executerHandle)
{
  if (currentNumberSub < MAX_SUBSCRIBER)
  {
    createSubscriber(&(subscribers[currentNumberSub]), type_support, topic_name);
    RCCHECK(rclc_executor_add_subscription(&executor_sub, &(subscribers[currentNumberSub]), msg, callback, executerHandle));
    currentNumberSub++;
    return currentNumberSub - 1;
  }
  else
  {
    Serial.println("ERROR. No more available space to register new subscriber");
    return -1;
  }
}

void initExecuterSub()
{
  RCCHECK(rclc_executor_init(&executor_sub, &support.context, MAX_SUBSCRIBER, &allocator));
}

void spinSub()
{
  RCSOFTCHECK(rclc_executor_spin_some(&executor_sub, RCL_MS_TO_NS(100)));
}