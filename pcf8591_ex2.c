#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

const int PCF8591_ADDR = 0x48;

int main(void)
{
    int fd;
    unsigned char value = 0;

    if (wiringPiSetup() == -1)
        return 1;

    fd = wiringPiI2CSetup(PCF8591_ADDR);
    if (fd == -1)
        return 1;

    while (1)
    {
        value += 5;

        // 0x40 = 10000000 (analog output enable flag = 1)
        wiringPiI2CWriteReg8(fd, 0x40, value);

        printf("Izlaz DA konvertora: %d\n", value);
        delay(50);
    }

    return 0;
}