#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>

struct measurements {
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int temperature;
};

extern char *optarg;
extern int optind, opterr, optopt;

typedef struct measurements data_t;

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

void init_data2(int size_meas, data_t *ukaz_meas, const char *strfile, int number_month)
   {
     FILE *fp = fopen(strfile, "r");
     int schetstrok = 0;
     int max_temp_year = -100;
     int min_temp_year = 100;
     int max_temp_month = -100;
     int min_temp_month = 100;
     int amount_temp = 0;
     int amount_temp_month = 0;
     int count_day_month = 0;
     
     ukaz_meas = malloc(size_meas * sizeof(data_t));

    while(!feof(fp))
    {
      fscanf(fp, "%d;%d;%d;%d;%d;%d",
                  &ukaz_meas->year,
                  &ukaz_meas->month,
                  &ukaz_meas->day,
                  &ukaz_meas->hours, 
                  &ukaz_meas->minutes,
                  &ukaz_meas->temperature);
      schetstrok++;
      if (schetstrok % 100 == 0)
         {
         ukaz_meas = realloc(ukaz_meas, schetstrok * sizeof(data_t));
         }
      if(number_month != 0 && ukaz_meas->month < (number_month + 1) && ukaz_meas->month > (number_month - 1))
      {
          if (ukaz_meas->temperature > max_temp_month) 
         {
            max_temp_month = ukaz_meas->temperature;
         }
          if (ukaz_meas->temperature < min_temp_month) 
         {
            min_temp_month = ukaz_meas->temperature;
         }
       count_day_month++;
       amount_temp_month = amount_temp_month + ukaz_meas->temperature;
      }
      else
      {
      if (ukaz_meas->temperature > max_temp_year) 
        {
            max_temp_year = ukaz_meas->temperature;
        }
      if (ukaz_meas->temperature < min_temp_year) 
        {
            min_temp_year = ukaz_meas->temperature;
        }
       amount_temp = amount_temp + ukaz_meas->temperature;
      }
    }
    if(number_month != 0)
    {
    printf("max_temp_month = %d min_temp_month = %d average_month_temp = %d\n", max_temp_month, min_temp_month, amount_temp_month/count_day_month);
    printf("number of lines per month  = %d\n", count_day_month);
    }
    else
    printf("max_temp_year = %d, min_temp_year = %d, average_year_temp = %d\n", max_temp_year, min_temp_year, amount_temp/schetstrok);
     printf("number of lines in the file = %d\n", schetstrok);
     fclose(fp);
     free(ukaz_meas);
    } 
