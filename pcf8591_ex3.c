/*Povezati izlaz DAC-a sa AIN2 (koji je slobodan)
* očitavati trimer potenciometar koji je na AIN3
* upisati tu vrednost u DAC,
* očitati DAC preko AIN2
* DAC izlaz je validan do oko ~220
*/

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

const int PCF8591_ADDR = 0x48;
int fd, adcVal;

int main(void) {
	if (wiringPiSetup () == -1) 
		return 1;
		
	fd = wiringPiI2CSetup(PCF8591_ADDR);
	if (fd == -1)
        return 1;
	
	while (1) {
		// procitaj trimer pot sa AIN3 ulaza
		wiringPiI2CReadReg8(fd, 0x43);		// dummy
		adcVal = wiringPiI2CReadReg8(fd, 0x43);
		printf("Pot ADC vrednost = %d\t", adcVal);
		
		// upisi tu vrednost u DAC
		wiringPiI2CWriteReg8(fd, 0x40, adcVal);
		
		// procitaj DAC preko AIN2
		wiringPiI2CReadReg8(fd, 0x42) ;		// dummy
		adcVal = wiringPiI2CReadReg8(fd, 0x42);
		printf("DAC vrednost = %d \n\n" , adcVal);
		
		delay(500);
	}
	
	return 0;
}