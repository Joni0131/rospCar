#include "MicroRosMain.h"

rcl_allocator_t allocator;
rclc_support_t support;
rcl_node_t node;

void error_loop()
{
    while (1)
    {
        delay(100);
    }
}

void initMicroRos()
{
    Serial.println("Start Wifi.");
    setupWifi();
    Serial.println("Start Alloctor.");
    setupAllocator();
    Serial.println("Start Init Options.");
    createInitOptions();
    Serial.println("Start Node.");
    createNode();
}

void createNode()
{
    // create node
    RCCHECK(rclc_node_init_default(&node, "micro_ros_platformio_node", "", &support));
}

void createInitOptions()
{
    // create init_options
    RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
}

void setupWifi()
{
    IPAddress ipAddress = IPAddress(IPADDRESS); // IP Address of recieving device
    String ssid = SSID;
    String pass = PASSWORD;

    set_microros_wifi_transports(ssid.begin(), pass.begin(), ipAddress, 8888);
    delay(2000);
}

void setupAllocator()
{
    allocator = rcl_get_default_allocator();
}
