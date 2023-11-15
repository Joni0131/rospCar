#include "UltrSoundSensor.h"

NewPing sonar(PIN_ULTRASOUND_TRIG, PIN_ULTRASOUND_ECHO, ULTRA_MAX_DISTANCE_CM);

void setupUltraSoundSensor(custom_interfaces__msg__UltraSonicSensor * ultraSoundMSG)
{
    Serial.println(F("Initializing Ultra Sound Sensor..."));

    ultraSoundMSG->id = 0;

    Serial.println(F("Ultra Sound Sensor ready."));
}

void ultrasound_callback(custom_interfaces__msg__UltraSonicSensor * ultraSoundMSG)
{
    ultraSoundMSG->distance = (sonar.ping() / 2) * 0.0343;
}
