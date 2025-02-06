#include <zephyr/kernel.h>

int main(void)
{
        while (1) {
                k_msleep(100U); // Sleep for 100 ms.
        }
        
        return 0;
}

