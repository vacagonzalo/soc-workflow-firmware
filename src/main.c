/* C standard includes */

/* BSP includes */
#include "FreeRTOS.h"
#include "task.h"

/* Project includes */
#include "utils.h"

void hello_world(void *unused) {
  while (1) {
    LPRINTF("Hello World!\n");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

int main(void) {
  BaseType_t res;

  res = xTaskCreate(TASK_FUNCTION(hello_world), TASK_NAME("hello_world"),
                    TASK_SIZE(SIZE_SMALL), TASK_ARGUMENT(NO_ARGUMENT),
                    TASK_PRIORITY(PRIORITY_MEDIUM), TASK_HANDLER(NO_HANDLER));
  configASSERT(pdPASS == res);

  vTaskStartScheduler();

  LPERROR("FreeRTOS scheduler failed\n");
  while (1)
    ;

  LPERROR("Reached the end of main\n");
  return 0; /* Avoid warnings */
}
