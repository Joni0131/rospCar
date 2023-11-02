#include "NerveSystem.h"

void setupI2C() {
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
    #endif
}

void setupAll() {
    setupI2C();
    setupAccelerometer();
}

void generatePublishers() {
    m_oAccelerromaterTopic.publisherID = registerPublisher(&(m_oAccelerromaterTopic.msg_type),m_oAccelerromaterTopic.publishTopic,m_oAccelerromaterTopic.timer_timeout,accelerometer_timer_callback);
}

void generateSubscribers() {
    
}
