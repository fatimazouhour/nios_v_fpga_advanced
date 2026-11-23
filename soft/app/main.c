#include <stdio.h>
#include <unistd.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"

#define NB_LEDS  10
#define DELAY_US 100000

int main(void)
{
    int pos = 0;
    int dir = 1;

    printf("LED chaser started\n");

    while (1) {
        IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE, 1 << pos);
        usleep(DELAY_US);

        pos += dir;
        if (pos == NB_LEDS - 1 || pos == 0)
            dir = -dir;              // bounce at both ends
    }
    return 0;
}
