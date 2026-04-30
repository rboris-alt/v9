#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

const int PCF8591_ADDR = 0x48;

int main(void)
{
    int fd;
    int adc0, adc1, adc2, adc3;

    if (wiringPiSetup() == -1)
        return 1;

    fd = wiringPiI2CSetup(PCF8591_ADDR);
    if (fd == -1)
        return 1;

    while (1)
    {
		// kanal 0
        wiringPiI2CReadReg8(fd, 0x00);     // prethodna vrednost
        adc0 = wiringPiI2CReadReg8(fd, 0x00);

        // kanal 1
        wiringPiI2CReadReg8(fd, 0x01);  	// prethodna vrednost
        adc1 = wiringPiI2CReadReg8(fd, 0x01);

        // kanal 2
        wiringPiI2CReadReg8(fd, 0x02);		// prethodna vrednost
        adc2 = wiringPiI2CReadReg8(fd, 0x02);

        // kanal 3
        wiringPiI2CReadReg8(fd, 0x03);		// prethodna vrednost
        adc3 = wiringPiI2CReadReg8(fd, 0x03);

        printf("adc0: %5.2f  adc1: %5.2f  adc2: %5.2f  adc3: %5.2f\r",
				adc0 * 3.3 / 255.0,
				adc1 * 3.3 / 255.0,
				adc2 * 3.3 / 255.0,
				adc3 * 3.3 / 255.0);
        fflush(stdout);

        delay(100);
    }

    return 0;
}
