#include <zephyr/kernel.h>
#define SLEEP_TIME_MS   100U

int main(void)
{
        printk("Message from freestanding project.\n");
        while (1) {
                k_msleep(SLEEP_TIME_MS); // Sleep for 100 ms.
        }
        
        return 0;
}

