#include "dzkurs.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>


extern char *optarg;
extern int optind, opterr, optopt;

void init_data2(int size_meas, data_t *ukaz_meas, const char *strfile, int number_month);

int main(int argc, char *argv[])
{
  const char *opts = "m::f:h::";
  int ret;
  int size_meas = 5;
  int number_month;
  data_t meas[size_meas];
  data_t *ukaz_meas = &meas[size_meas];
  memset(meas, 0, sizeof(meas));
  
while ((ret = getopt(argc, argv, opts)) != -1)
     {
          switch(ret)
          {
          case 'm' :
           {
            number_month = atoi(argv[2]);
            printf("number_month = %d\n", number_month);
            break;
           }
          case 'f' :
           {
           printf("file for analysis = %s\n", optarg);
           init_data2(size_meas, &meas[size_meas], optarg, number_month);
           break;
           }
           case 'h' :
            {
            printf("Please enter the name of the analyzed file with the '-f' key\n");
            printf("If you want statistics for a month, enter the number of the month with the '-m' key\n");
            printf("If you want statistics for the year, do not specify the month\n");
            break;
            }
           }
       }
  return 0;
}
