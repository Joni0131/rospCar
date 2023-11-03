#include "MicroRosTX.h"

#include "custom_interfaces/msg/servo_motor.h"

rclc_executor_t executor_pub;
rcl_publisher_t publishers[MAX_PUBLISHER];
rcl_timer_t timers[MAX_PUBLISHER];
std_msgs__msg__Int32 msg;

int currentNumberPub = 0;

int test_id = 3;

std_msgs__msg__Int32 current_PWM;
custom_interfaces__msg__ServoMotor cusmsg;

const char *motor_info_topic = "motor_info_topic";

void createPublisher(rcl_publisher_t *publisher, const rosidl_message_type_support_t *type_support, const char *topic_name)
{
    // create publisher
    RCCHECK(rclc_publisher_init_default(
        publisher,
        &node,
        type_support,
        topic_name));
}

void createTimer(rcl_timer_t *timer, const unsigned int timer_timeout, rcl_timer_callback_t callback)
{
    // create timer,
    RCCHECK(rclc_timer_init_default(
        timer,
        &support,
        RCL_MS_TO_NS(timer_timeout),
        callback));
}

void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        RCSOFTCHECK(rcl_publish(&(publishers[test_id]), &cusmsg, NULL));
    }
}

void interimsPublishStart()
{
    cusmsg.id = 5;
    cusmsg.angle = 15;
    Serial.println("Start ExecPub.");
    initExecuterPub();
    Serial.println("Start Pub.");
    test_id = registerPublisher(ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, ServoMotor), motor_info_topic, 1000, timer_callback);
}

void spinPub()
{
    RCSOFTCHECK(rclc_executor_spin_some(&executor_pub, RCL_MS_TO_NS(100)));
}

void initExecuterPub()
{
    RCCHECK(rclc_executor_init(&executor_pub, &support.context, MAX_PUBLISHER, &allocator));
}

int registerPublisher(const rosidl_message_type_support_t *type_support, const char *topic_name, const unsigned int timer_timeout, rcl_timer_callback_t callback)
{
    if (currentNumberPub < MAX_PUBLISHER)
    {
        createPublisher(&(publishers[currentNumberPub]), type_support, topic_name);
        createTimer(&(timers[currentNumberPub]), timer_timeout, callback);
        currentNumberPub++;
        return currentNumberPub - 1;
    }
    else
    {
        Serial.println("ERROR. No more available space to register new publisher");
        return -1;
    }
}

void addAllToExecutor(){
    for(int i = 0; i < currentNumberPub; i++){
        Serial.println((int)&(publishers[i]));
        Serial.println((int)&(timers[i]));
        RCCHECK(rclc_executor_add_timer(&executor_pub, &(timers[i])));
    }
}