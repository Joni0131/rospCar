#include "ImpulsionMotor.h"

ImpulsionTopicInfo m_oImpulsionTopicInfo;
ImpulsionTopicTarget m_oImpulsionTopicTarget;

void setupImpulsionMotor()
{
    Serial.println(F("Initializing Impulsion motor..."));

    m_oImpulsionTopicInfo.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, ImpulsionMotor);
    m_oImpulsionTopicTarget.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, ImpulsionMotor);
    m_oImpulsionTopicInfo.msg.id = 0;
    m_oImpulsionTopicTarget.msg.id = 0;

    pinMode(PIN_IMPULSION_ENABLE, OUTPUT);
    pinMode(PIN_IMPULSION_FORWARD, OUTPUT);
    pinMode(PIN_IMPULSION_BACKWARD, OUTPUT);

    analogWrite(PIN_IMPULSION_FORWARD, 0);
    analogWrite(PIN_IMPULSION_BACKWARD, 0);
    digitalWrite(PIN_IMPULSION_ENABLE, HIGH);

    Serial.println(F("Impulsion motor ready."));
}

void impulsion_timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        int forward = analogRead(PIN_IMPULSION_FORWARD);
        int backward = analogRead(PIN_IMPULSION_BACKWARD);
        int dir = 0;
        int pwm = 0;
        if (forward > 0)
        {
            dir = 1;
            pwm = forward;
        }
        else if (backward > 0)
        {
            dir = -1;
            pwm = backward;
        }
        m_oImpulsionTopicInfo.msg.direction = dir;
        m_oImpulsionTopicInfo.msg.pwm = pwm;
        RCSOFTCHECK(rcl_publish(&(publishers[m_oImpulsionTopicInfo.publisherID]), &m_oImpulsionTopicInfo.msg, NULL));
    }
}

void impulsion_subscriber_callback(const void *msgin)
{
    // Cast received message to used type
    const custom_interfaces__msg__ImpulsionMotor *local_msg = (const custom_interfaces__msg__ImpulsionMotor *)msgin;
    if (local_msg->direction == 1)
    {
        if (local_msg->pwm > MAXIMPULSIONSPEED)
        {
            analogWrite(PIN_IMPULSION_BACKWARD, 0);
            analogWrite(PIN_IMPULSION_FORWARD, MAXIMPULSIONSPEED);
            m_oImpulsionTopicTarget.msg.pwm = MAXIMPULSIONSPEED;
        }
        else if (local_msg->pwm > 0)
        {
            analogWrite(PIN_IMPULSION_BACKWARD, 0);
            analogWrite(PIN_IMPULSION_FORWARD, 0);
            m_oImpulsionTopicTarget.msg.pwm = 0;
        }
        else
        {
            analogWrite(PIN_IMPULSION_BACKWARD, 0);
            analogWrite(PIN_IMPULSION_FORWARD, local_msg->pwm);
            m_oImpulsionTopicTarget.msg.pwm = local_msg->pwm;
        }
    }
    else if (local_msg->direction == -1)
    {
        if (local_msg->pwm > MAXIMPULSIONSPEED)
        {
            analogWrite(PIN_IMPULSION_FORWARD, 0);
            analogWrite(PIN_IMPULSION_BACKWARD, MAXIMPULSIONSPEED);
            m_oImpulsionTopicTarget.msg.pwm = MAXIMPULSIONSPEED;
        }
        else if (local_msg->pwm > 0)
        {
            analogWrite(PIN_IMPULSION_FORWARD, 0);
            analogWrite(PIN_IMPULSION_BACKWARD, 0);
            m_oImpulsionTopicTarget.msg.pwm = 0;
        }
        else
        {
            analogWrite(PIN_IMPULSION_FORWARD, 0);
            analogWrite(PIN_IMPULSION_BACKWARD, local_msg->pwm);
            m_oImpulsionTopicTarget.msg.pwm = local_msg->pwm;
        }
    }
    else
    {
        analogWrite(PIN_IMPULSION_FORWARD, 0);
        analogWrite(PIN_IMPULSION_BACKWARD, 0);
        m_oImpulsionTopicTarget.msg.pwm = 0;
    }
    m_oImpulsionTopicTarget.msg.direction = local_msg->direction;
}
