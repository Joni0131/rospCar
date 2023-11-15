#include "ToFSensor.h"

VL53L1X tof_sensor;

void setupToFSensor(custom_interfaces__msg__ToFSensor * toFSensorMSG)
{
    Serial.println(F("Initializing ToF Sensor..."));

    toFSensorMSG->id = 0;

    tof_sensor.setTimeout(500);

    if (!tof_sensor.init())
    {
        Serial.println(F("Failed to boot VL53L1X"));
        while (1)
            ;
    }

    tof_sensor.setDistanceMode(VL53L1X::Long);
    tof_sensor.setMeasurementTimingBudget(50000);

    // start continuous ranging
    tof_sensor.startContinuous(10);

    Serial.println(F("ToF Sensor ready."));
}

void tofsensor_callback(custom_interfaces__msg__ToFSensor * toFSensorMSG)
{
    tof_sensor.read();

    toFSensorMSG->distance = tof_sensor.ranging_data.range_mm / 10;
}
