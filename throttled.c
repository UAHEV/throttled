#include <linux/i2cWrappers.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

#define potentiometer 0x09

int main(int argc, const char **argv) {

  FILE *dataFile;
  datafile = fopen("/tmp/test.txt", "w");

  while(1) {
  
		int data = i2cRead(potentiometer);
    
    fprintf(datafile, "%d\n", data);
    
  }
  
  printf("Ending throttled execution...");
  
  return 0
  
}
