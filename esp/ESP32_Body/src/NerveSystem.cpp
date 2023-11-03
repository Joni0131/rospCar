#include "NerveSystem.h"

void setupI2C() {
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #endif
}

void setupPWM(){
    ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
}

void setupAll() {
    setupI2C();
    setupPWM();
    setupAccelerometer();
    setupSteeringMotor();
}

void generatePublishers() {
    Serial.println("Register Accelerometer Pub");
    m_oAccelerromaterTopic.publisherID = registerPublisher(&(m_oAccelerromaterTopic.msg_type),m_oAccelerromaterTopic.publishTopic,m_oAccelerromaterTopic.timer_timeout,accelerometer_timer_callback);
    Serial.println("Register Servo Pub");
    m_oServoTopicInfo.publisherID = registerPublisher(&(m_oServoTopicInfo.msg_type),m_oServoTopicInfo.publishTopic,m_oServoTopicInfo.timer_timeout,servo_timer_callback);
}

void generateSubscribers() {
    Serial.println("Register Servo Sub");
    m_oServoTopicTarget.subscriberID = registerSubscriber(&(m_oServoTopicTarget.msg_type),m_oServoTopicTarget.subscriberTopic,&(m_oServoTopicTarget.msg),servo_subscriber_callback, ON_NEW_DATA);    
}
