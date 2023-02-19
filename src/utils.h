#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#ifndef TEST
#include "xil_printf.h"
#define LPRINTF(fmt, ...) xil_printf("%s():%u " fmt, __func__, __LINE__, ##__VA_ARGS__)
#define LPERROR(fmt, ...) LPRINTF("ERROR: " fmt, ##__VA_ARGS__)
#else
#define LPRINTF(fmt, ...)
#define LPERROR(fmt, ...)
#endif

#ifdef DEBUG
#define LPRINTFDEBUG(x) LPRINTF(x)
#else
#define LPRINTFDEBUG(x)
#endif

#define PRIORITY_LOW 1
#define PRIORITY_MEDIUM 2
#define PRIORITY_HIGH 3
#define PRIORITY_CRITICAL 4

#define SIZE_SMALL 1
#define SIZE_MEDIUM 2
#define SIZE_BIG 3
#define SIZE_HUGE 4

#define NO_ARGUMENT 0

#define NO_HANDLER NULL

#define TASK_FUNCTION(f) f
#define TASK_NAME(n) (const char *)n
#define TASK_SIZE(s) (1024 * s)
#define TASK_PRIORITY(p) (tskIDLE_PRIORITY + p)
#define TASK_ARGUMENT(a) (void *)a
#define TASK_HANDLER(h) h

#endif /* SRC_UTILS_H_ */
