#include "Accelerometer.h"

MPU6050 mpu;
AccelerometerTopic m_oAccelerromaterTopic;

void defaultCaliberAccelerometer(){
    mpu.setXGyroOffset(INITIALXGYRO);
    mpu.setYGyroOffset(INITIALYGYRO);
    mpu.setZGyroOffset(INITIALZGYRO);
    mpu.setXAccelOffset(INITIALXACCEL); 
    mpu.setYAccelOffset(INITIALYACCEL); 
    mpu.setZAccelOffset(INITIALZACCEL);

    m_oAccelerromaterTopic.msg.offset.xaccel = INITIALXACCEL;
    m_oAccelerromaterTopic.msg.offset.yaccel = INITIALYACCEL;
    m_oAccelerromaterTopic.msg.offset.zaccel = INITIALZACCEL;
    m_oAccelerromaterTopic.msg.offset.xgyro = INITIALXGYRO;
    m_oAccelerromaterTopic.msg.offset.ygyro = INITIALYGYRO;
    m_oAccelerromaterTopic.msg.offset.zgyro = INITIALZGYRO;
}

void setupAccelerometer() {
    
    m_oAccelerromaterTopic.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, AccelerationSensor);

    mpu.initialize();
    pinMode(PIN_ACCELEROMETER_INTERUPT, INPUT);
    Serial.println(F("Initializing Accelerometer..."));

    // Set default callibaration values
    defaultCaliberAccelerometer();

    Serial.println(F("Accelerometer ready."));
}

void accelerometer_timer_callback(rcl_timer_t *timer, int64_t last_call_time) {
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {

        //acceleration is   0      | +/- 2g             | 8192 LSB/mg
        //gyro is           0      | +/- 250 degrees/s  | 131 LSB/deg/s
        mpu.getMotion6(&(m_oAccelerromaterTopic.msg.movement.xaccel),&(m_oAccelerromaterTopic.msg.movement.yaccel),&(m_oAccelerromaterTopic.msg.movement.zaccel),&(m_oAccelerromaterTopic.msg.movement.xgyro),&(m_oAccelerromaterTopic.msg.movement.ygyro),&(m_oAccelerromaterTopic.msg.movement.zgyro));

        RCSOFTCHECK(rcl_publish(&(publishers[m_oAccelerromaterTopic.publisherID]), &m_oAccelerromaterTopic.msg, NULL));
    }
}

void caliberAccelerometer(){
    //TODO: Implement calibration
    mpu.setXGyroOffset(INITIALXGYRO);
    mpu.setYGyroOffset(INITIALYGYRO);
    mpu.setZGyroOffset(INITIALZGYRO);
    mpu.setXAccelOffset(INITIALXACCEL); 
    mpu.setYAccelOffset(INITIALYACCEL); 
    mpu.setZAccelOffset(INITIALZACCEL);

    m_oAccelerromaterTopic.msg.offset.xaccel = INITIALXACCEL;
    m_oAccelerromaterTopic.msg.offset.yaccel = INITIALYACCEL;
    m_oAccelerromaterTopic.msg.offset.zaccel = INITIALZACCEL;
    m_oAccelerromaterTopic.msg.offset.xgyro = INITIALXGYRO;
    m_oAccelerromaterTopic.msg.offset.ygyro = INITIALYGYRO;
    m_oAccelerromaterTopic.msg.offset.zgyro = INITIALZGYRO;
}

void my_service_callback(const void * req, void * res) {
  // Process the request and fill the response
}