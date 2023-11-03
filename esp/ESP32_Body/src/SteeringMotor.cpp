#include "SteeringMotor.h"

Servo myservo;
ServoTopicInfo m_oServoTopicInfo;
ServoTopicTarget m_oServoTopicTarget;

void setupSteeringMotor() {
    Serial.println(F("Initializing Steering motor..."));
    m_oServoTopicInfo.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, ServoMotor);
    m_oServoTopicTarget.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, ServoMotor);
    m_oServoTopicInfo.msg.id = 0;
    m_oServoTopicTarget.msg.id = 0;
    myservo.setPeriodHertz(50);
    myservo.attach(PIN_STEERING_MOTOR);
    Serial.println(F("Steering motor ready."));
}

void servo_timer_callback(rcl_timer_t *timer, int64_t last_call_time) {
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        m_oServoTopicInfo.msg.angle = myservo.read(); 
        RCSOFTCHECK(rcl_publish(&(publishers[m_oServoTopicInfo.publisherID]), &m_oServoTopicInfo.msg, NULL));
    }
}

void servo_subscriber_callback(const void *msgin) {
    // Cast received message to used type
    const custom_interfaces__msg__ServoMotor *local_msg = (const custom_interfaces__msg__ServoMotor *)msgin;
    if(local_msg->angle <= SERVOMAX){
        if(local_msg->angle >= SERVOMIN){
            m_oServoTopicTarget.msg.angle = local_msg->angle;
        }else{
            m_oServoTopicTarget.msg.angle = SERVOMIN;
        }
    }else{
        m_oServoTopicTarget.msg.angle = SERVOMAX;
    }
    myservo.write(m_oServoTopicTarget.msg.angle);
}
