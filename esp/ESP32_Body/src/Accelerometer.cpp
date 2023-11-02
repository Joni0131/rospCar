#include "Accelerometer.h"

MPU6050 mpu;
AccelerometerTopic m_oAccelerromaterTopic;
uint8_t devStatus; 
bool dmpReady = false;  
uint8_t mpuIntStatus;  
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

volatile bool mpuInterrupt = false;
void dmpDataReady() {
    mpuInterrupt = true;
}

void setupAccelerometer() {
    
    m_oAccelerromaterTopic.msg_type = *ROSIDL_GET_MSG_TYPE_SUPPORT(custom_interfaces, msg, AccelerationSensor);

    mpu.initialize();
    pinMode(PIN_ACCELEROMETER_INTERUPT, INPUT);
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    mpu.setXGyroOffset(INITIALXGYRO);
    mpu.setYGyroOffset(INITIALYGYRO);
    mpu.setZGyroOffset(INITIALZGYRO);
    mpu.setZAccelOffset(INITIALZACCEL); 

    if (devStatus == 0) {
        
        mpu.CalibrateAccel(6);
        mpu.CalibrateGyro(6);
        mpu.PrintActiveOffsets();
        
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        
        Serial.print(F("Enabling interrupt detection (Arduino external interrupt "));
        Serial.print(digitalPinToInterrupt(PIN_ACCELEROMETER_INTERUPT));
        Serial.println(F(")..."));
        attachInterrupt(digitalPinToInterrupt(PIN_ACCELEROMETER_INTERUPT), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }  
}

void accelerometer_timer_callback(rcl_timer_t *timer, int64_t last_call_time) {
    RCLC_UNUSED(last_call_time);
    if (timer != NULL)
    {
        //TODO: read out sensor and write to msg
        RCSOFTCHECK(rcl_publish(&(publishers[m_oAccelerromaterTopic.publisherID]), &m_oAccelerromaterTopic.msg, NULL));
    }
}
