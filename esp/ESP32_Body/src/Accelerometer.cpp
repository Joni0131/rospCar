#include "Accelerometer.h"

MPU6050 mpu;
AccelerometerTopic m_oAccelerromaterTopic;

void caliberAccelerometer(){
    //TODO: fill this function
}

void setupAccelerometer() {
    
    m_oAccelerromaterTopic.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, AccelerationSensor);

    mpu.initialize();
    pinMode(PIN_ACCELEROMETER_INTERUPT, INPUT);
    Serial.println(F("Initializing Accelerometer..."));

    mpu.setXGyroOffset(INITIALXGYRO);
    mpu.setYGyroOffset(INITIALYGYRO);
    mpu.setZGyroOffset(INITIALZGYRO);
    mpu.setXAccelOffset(INITIALXACCEL); 
    mpu.setYAccelOffset(INITIALYACCEL); 
    mpu.setZAccelOffset(INITIALZACCEL);

    caliberAccelerometer();

    m_oAccelerromaterTopic.msg.offset.xaccel = INITIALXACCEL;
    m_oAccelerromaterTopic.msg.offset.yaccel = INITIALYACCEL;
    m_oAccelerromaterTopic.msg.offset.zaccel = INITIALZACCEL;
    m_oAccelerromaterTopic.msg.offset.xgyro = INITIALXGYRO;
    m_oAccelerromaterTopic.msg.offset.ygyro = INITIALYGYRO;
    m_oAccelerromaterTopic.msg.offset.zgyro = INITIALZGYRO;

    Serial.println(F("Accelerometer ready."));
}

void accelerometer_timer_callback(rcl_timer_t *timer, int64_t last_call_time) {
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        mpu.getMotion6(&(m_oAccelerromaterTopic.msg.movement.xaccel),&(m_oAccelerromaterTopic.msg.movement.yaccel),&(m_oAccelerromaterTopic.msg.movement.zaccel),&(m_oAccelerromaterTopic.msg.movement.xgyro),&(m_oAccelerromaterTopic.msg.movement.ygyro),&(m_oAccelerromaterTopic.msg.movement.zgyro));
        RCSOFTCHECK(rcl_publish(&(publishers[m_oAccelerromaterTopic.publisherID]), &m_oAccelerromaterTopic.msg, NULL));
    }
}
