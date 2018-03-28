#include<iostream>
#include <stdio.h>
using namespace std;

int main()
{
  char value_str[7];
  long int value_int = 0;
  cout << "ADC Read Start" << '\n';
  FILE *ADCStream = fopen("/sys/bus/iio/devices/iio\:device0/in_voltage0_raw", "r");
  // char *ADCvalue = "/sys/bus/iio/devices/iio\:device0/in_voltage0_raw";

  for(int i=0; i<10; i++)
  {
    fread(&value_str, 6, 6, ADCStream);
    value_int = strtol(value_str,NULL,0);
    printf("0 %li\n", value_int);
    fflush(stdout);
    sleep(1);
  }

}
