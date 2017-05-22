#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//defines
//#define ADDRESS 0x08
//#define DEBUG.
#define OFF_STATE 100


int i2cRead(int ADDRESS) {

	//Open the file
	int file = open("/dev/i2c-1", O_RDWR);

//#ifdef DEBUG
//	printf("i2cRead File Descriptor: %d\n", file);
//#endif



	//check the file
	if(file < 0) {

		fprintf(stderr, "There was an error opening the i2c file: %m\n");
		close(file);
		return OFF_STATE;

	}

	if(ioctl(file, I2C_SLAVE, ADDRESS) < 0) {

		fprintf(stderr, "Failed to obtain handle for slave address: %m\n");
		close(file);
		return OFF_STATE;

	}

	//read the device
	int data = i2c_smbus_read_byte(file);

	if (data < 0) {

		fprintf(stderr, "Error reading device: %m\n");
		close(file);
		return OFF_STATE;

	}
//	else {
//
//		//printf("Recieved %d from device", data);
//		close(file);
//		return data;
//
//	}


	//and return the data
	close(file);
	return data;


}


int i2cWrite(int address, unsigned char data) {

	int file = open("/dev/i2c-1", O_RDWR);

//#ifdef DEBUG
//	printf("i2cWrite File Descriptor: %d\n", file);
//#endif


	if (file < 0) {

		fprintf(stderr, "Erro Reading File: %m\n");
		close(file);
		return 0;

	}

	if (ioctl(file, I2C_SLAVE, address) < 0) {

		fprintf(stderr, "Error opening device: %m\n");
		close(file);
		return 0;

	}

	//now write
//	if (i2c_smbus_write_word_data(file, NULL, data) < 0) {
//
//		fprintf(stderr, "Error writing: %m\n");
//		return -9;
//
//	}
//	else {
//
//		printf("Success!\n");
//		close(file);
//		return 0;
//
//	}

	char buf[10];
	buf[0] = data;

	if (write(file, buf, 1) != 1) {

		fprintf(stderr, "error writing to device: %m\n");
		close(file);
		return 0;

	}
//	else {
//
//		printf("Write Successful!");
//		return 0;
//
//	}

	//close the file
	close(file);
	return 0;

}
