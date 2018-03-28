#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main()
{
  char value_str[2];
  long int value_int = 0;
  cout << "ADC Read Start" << '\n';
  // FILE *ADCStream = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");
  // char *ADCvalue = "/sys/bus/iio/devices/iio\:device0/in_voltage0_raw";

  for(int i=0; i<10; i++)
  {
    FILE *ADCStream = fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw", "r");
    fread(&value_str, 1, 2, ADCStream);
    //cout << value_str << '\n';
    //value_int = strtol(value_str,NULL,0);
    printf("READ #%i: %x\n", i, value_str);
    fflush(stdout);
    usleep(1000000);
    fclose(ADCStream);
  }

}
