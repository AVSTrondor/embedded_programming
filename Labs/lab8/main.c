

/**
 * main.c
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"
#include "systick_frt.h"
#include "FreeRTOS.h"
#include "task.h"
#include "status_led.h"
#include "led.h"

#define USERTASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define IDLE_PRIO 0
#define LOW_PRIO  1
#define MED_PRIO  2
#define HIGH_PRIO 3

static void setupHardware(void)
/*****************************************************************************
*   Input    :  -
*   Output   :  -
*   Function :
*****************************************************************************/
{
  // TODO: Put hardware configuration and initialisation in here

  // Warning: If you do not initialize the hardware clock, the timings will be inaccurate
  init_systick();
  status_led_init();
  led_init();
  init_adc();
}

int main(void)
{
    setupHardware();
    xTaskCreate( status_led_task, "Status_led", USERTASK_STACK_SIZE, NULL, LOW_PRIO, NULL );
    xTaskCreate( green_led_task, "Green_led", USERTASK_STACK_SIZE, NULL, LOW_PRIO, NULL );
    xTaskCreate( yellow_led_task, "Yellow_led", USERTASK_STACK_SIZE, NULL, LOW_PRIO, NULL );
    xTaskCreate( red_led_task, "Red_led", USERTASK_STACK_SIZE, NULL, LOW_PRIO, NULL );
    vTaskStartScheduler();
	return 0;
}
