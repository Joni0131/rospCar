#include "NerveSystem.h"

void setupI2C()
{
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
#endif
}

void setupPWM()
{
    ESP32PWM::allocateTimer(PWM_CHANNEL0);
    ESP32PWM::allocateTimer(PWM_CHANNEL1);
    ESP32PWM::allocateTimer(PWM_CHANNEL2);
    ESP32PWM::allocateTimer(PWM_CHANNEL3);

    ledcSetup(PWM_CHANNEL_FORWARD, PWM_FREQ, PWM_RESO);
    ledcSetup(PWM_CHANNEL_BACKWARD, PWM_FREQ, PWM_RESO);
}

void setupAll()
{
    setupI2C();
    setupPWM();
    setupAccelerometer();
    setupSteeringMotor();
    setupImpulsionMotor();
}

void generatePublishers()
{
    Serial.println("Register Accelerometer Pub");
    m_oAccelerromaterTopic.publisherID = registerPublisher(&(m_oAccelerromaterTopic.msg_type), m_oAccelerromaterTopic.publishTopic, m_oAccelerromaterTopic.timer_timeout, accelerometer_timer_callback);
    Serial.println("Register Servo Pub");
    m_oServoTopicInfo.publisherID = registerPublisher(&(m_oServoTopicInfo.msg_type), m_oServoTopicInfo.publishTopic, m_oServoTopicInfo.timer_timeout, servo_timer_callback);
    Serial.println("Register Impulsion Motor Pub");
    m_oImpulsionTopicInfo.publisherID = registerPublisher(&(m_oImpulsionTopicInfo.msg_type), m_oImpulsionTopicInfo.publishTopic, m_oImpulsionTopicInfo.timer_timeout, impulsion_timer_callback);
}

void generateSubscribers()
{
    Serial.println("Register Servo Sub");
    m_oServoTopicTarget.subscriberID = registerSubscriber(&(m_oServoTopicTarget.msg_type), m_oServoTopicTarget.subscriberTopic, &(m_oServoTopicTarget.msg), servo_subscriber_callback, ON_NEW_DATA);
    Serial.println("Register Impulsion Sub");
    m_oImpulsionTopicTarget.subscriberID = registerSubscriber(&(m_oImpulsionTopicTarget.msg_type), m_oImpulsionTopicTarget.subscriberTopic, &(m_oImpulsionTopicTarget.msg), impulsion_subscriber_callback, ON_NEW_DATA);
}
