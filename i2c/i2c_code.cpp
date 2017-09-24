#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>

#define I2C_ADDRESS			0x29
#define ENABLE_REG			0x80 //Enable Register 			0x00|0x00 WRITE = 0x00
#define RGBC_REG			0x81 //RGBC Timing Register 		0x01|0x00 WRITE = 0x00
#define CONTROL_REG			0x8F //Control Register			0x0F|0x00 WRITE = 0x00

#define R_LOW				0x96 // RDATAL LOW 			0x16|0x80 READ = 0x80
#define R_HIGH				0x97 // RDATAL HIGH 			0x17|0x80 READ = 0x80
#define G_LOW				0x98 // GDATAL LOW 			0x19|0x80 READ = 0x80
#define G_HIGH				0x99 // RDATAL HIGH 			0x18|0x80 READ = 0x80
#define B_LOW				0x9A // BDATAL LOW 			0x1A|0x80 READ = 0x80
#define B_HIGH				0x9B // BDATAL HIGH			0x1B|0x80 READ = 0x80

using namespace std;

int main()
{
	int data;
	int fd;
	uint16_t R, G, B;

	fd = wiringPiI2CSetup(I2C_ADDRESS);
	if (fd == -1)
		return -1;

        printf("fd =%d\n", fd);

	data=wiringPiI2CRead(fd);
	//print data
        printf("data=%d\n", data);


	wiringPiI2CWriteReg8(fd, ENABLE_REG, (0x01|0x02));
	wiringPiI2CWriteReg8(fd, RGBC_REG, 0x00);
	wiringPiI2CWriteReg8(fd, CONTROL_REG, 0x01);

	for(;;)
	{

		R =  wiringPiI2CReadReg8(fd, R_LOW)&0xFF;
		R += wiringPiI2CReadReg8(fd, R_HIGH) << 8;
		G =  wiringPiI2CReadReg8(fd, G_LOW)&0xFF;
		G += wiringPiI2CReadReg8(fd, G_HIGH) << 8;
		B =  wiringPiI2CReadReg8(fd, B_LOW)&0xFF; 
		B += wiringPiI2CReadReg8(fd, B_HIGH) << 8;

		printf("R=%d   G=%d   B=%d\r\n", R, G, B);
		break;  
	}
	
}
