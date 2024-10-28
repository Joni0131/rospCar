#include "MicroRosSrv.h"

#include "custom_interfaces/srv/acceleromator_calibration.h" // Include your service

rclc_executor_t executor_srv; // Executor for services
rcl_service_t services[MAX_SERVICES]; // Array of services
custom_interfaces__srv__AcceleromatorCalibration_Request reqs[MAX_SERVICES]; // Array of request messages
custom_interfaces__srv__AcceleromatorCalibration_Response ress[MAX_SERVICES]; // Array of response messages

int currentNumberServices = 0;

void createService(rcl_service_t *service, const rosidl_service_type_support_t *type_support, const char *service_name)
{
    // create service
    RCCHECK(rclc_service_init_default(
        service,
        &node,
        type_support,
        service_name));
}

void service_callback(const void *req, void *res)
{
    // handle service request and fill response
}

int registerService(const rosidl_service_type_support_t *type_support, const char *service_name)
{
    if (currentNumberServices < MAX_SERVICES)
    {
        createService(&(services[currentNumberServices]), type_support, service_name);
        RCCHECK(rclc_executor_add_service(&executor_srv, &(services[currentNumberServices]), &(reqs[currentNumberServices]), &(ress[currentNumberServices]), service_callback));
        currentNumberServices++;
        return currentNumberServices - 1;
    }
    else
    {
        Serial.println("ERROR. No more available space to register new service");
        return -1;
    }
}

void spinSrv()
{
    RCSOFTCHECK(rclc_executor_spin_some(&executor_srv, RCL_MS_TO_NS(100)));
}

void initExecutorSrv()
{
    RCCHECK(rclc_executor_init(&executor_srv, &support.context, MAX_SERVICES, &allocator));
}

void addAllServicesToExecutor()
{
    // All services are already added to the executor in registerService
}