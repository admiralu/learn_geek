#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

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

void print_file_contents(const char *strfile, bool stat, char *month);
void print_measurements(int size_meas, data_t *ukaz_meas);
//void init_data(data_t *ukaz_meas);
void init_mem(int size_meas, data_t *ukaz_meas);
int init_data2(int *size_meas1, data_t *ukaz_meas, const char *strfile);
void print_data_info(data_t *ukaz_meas, int size_meas, int number_month, bool selstat);

int main(int argc, char *argv[])
{
  const char *opts = "h::m::f:";
  bool selstat = false;
  int ret;
  int size_meas = 8;
  int number_month;
  data_t meas[size_meas];
  data_t *ukaz_meas = &meas[size_meas];
  
while ((ret = getopt(argc, argv, opts)) != -1)
     {
          switch(ret)
          {
          case 'm' :
           {
            selstat =true;
            printf("argv[2] %s, selstat %d\n", argv[2], selstat);
            break;
           }
          case 'f' :
           {
           number_month = atoi(argv[2]);
           printf("number_month = %d, selstat %d\n", number_month, selstat);
           printf("optarg = %s\n", optarg);
           init_data2(&size_meas, &meas[size_meas], optarg);
           //print_file_contents(optarg, selstat, argv[2]);
           break;
           }
           case 'h' :
            {
            printf("Please enter the name of the analyzed file with the '-f' key\n");
            printf("If you want statistics for a month, enter the number of the month with the '-m' key in format 'mm'\n");
            printf("If you want statistics for the year, do not specify the month\n");
            break;
            }
           }
       }

  init_mem(size_meas, &meas[size_meas]);
  
  print_measurements(size_meas, meas);
  printf("temper 10 = %d\n", meas[9].minutes);
  printf("size_meas = %d\n", size_meas);
  print_data_info(ukaz_meas, size_meas, number_month, selstat);
/*typedef struct measurements meas_t;

void init_meas(meas_t *m)
{
    m->day = rand() % 31;
    m->month = rand() % 12;
    m->year = rand() % 3000;
    m->temperature = rand() % 200;
}

void print_meas(meas_t m)
{
    printf("Meas D:%d M:%d Y:%d T:%d\n", m.day, m.month, m.year, m.temperature);
}*/
  free(meas);
  return 0;
}

void print_measurements(int size_meas, data_t *meas)
  {
    for (int i=0; i<size_meas; i++)
       {
    printf("year        = %d\nmonth       = %d\nday         = %d\nhours       = %d\nminutes     = %d\ntemperature = %d\n", meas[i].year, meas[i].month, meas[i].day, meas[i].hours, meas[i].minutes, meas[i].temperature);
       }
  }

/*void init_data(data_t *ukaz_meas)
  {
         ukaz_meas->year = rand() % 200;
         ukaz_meas->month = rand() % 12;
         ukaz_meas->day = rand() % 31;
         ukaz_meas->hours = rand() % 24;
         ukaz_meas->minutes = rand() % 60;
         ukaz_meas->temperature = rand() % 200;
   }*/

void init_mem(int size_meas, data_t *ukaz_meas)
   {
     ukaz_meas = malloc(size_meas * sizeof(data_t));
   }

int init_data2(int *size_meas1, data_t *ukaz_meas, const char *strfile)
   {
     FILE *fp = fopen(strfile, "r");
     int schetstrok = 0;
    if (!fp) 
    {
      printf("Error opening file\n");
      EXIT_FAILURE;
    }

    while (!feof(fp)) 
    {
      data_t *ukaz_meas;
      int scanfret = fscanf(fp, "%d;%d;%d;%d;%d;%d",
                  &ukaz_meas->year,
                  &ukaz_meas->month,
                  &ukaz_meas->day,
                  &ukaz_meas->hours, 
                  &ukaz_meas->minutes,
                  &ukaz_meas->temperature);
      schetstrok++;
      printf("scanfret %d schetstrok =%d\n", scanfret, schetstrok);
    }
     *size_meas1 = schetstrok;
     fclose(fp);
     return *size_meas1;
    } 

void print_data_info(data_t *ukaz_meas, int size_meas, int number_month, bool selstat)
{
  int max_temp_year = ukaz_meas[0].temperature;
  int min_temp_year = 100;
  int average_annual_temp = 0;
  int max_temp_month = 0;
  int min_temp_month = 100;
  int average_month_temp = 0;
  int chet_day_month = 0;
  int amount_temp = 0;
  
  if (selstat = 1)
  {
  while(ukaz_meas->month = number_month)
   {
     if (ukaz_meas->temperature > max_temp_month) 
        {
            max_temp_month = ukaz_meas->temperature;
        }
      if (ukaz_meas->temperature < min_temp_month) 
        {
            min_temp_month = ukaz_meas->temperature;
        }
       chet_day_month++;
       amount_temp = amount_temp + ukaz_meas->temperature;
    }
    printf("max_temp_month = %d, min_temp_month = %d, average_month_temp = %d\n", max_temp_month, min_temp_month, amount_temp/chet_day_month);
   }
  else if(selstat = 0)
  {   
  for (int i = 0; i < size_meas; i++) 
   {
     if (ukaz_meas[i].temperature > max_temp_year) 
        {
            max_temp_year = ukaz_meas[i].temperature;
        }
     if (ukaz_meas[i].temperature < min_temp_year) 
        {
            min_temp_year = ukaz_meas[i].temperature;
        }
       amount_temp = amount_temp + ukaz_meas[i].temperature;
    }
    printf("max_temp_year = %d, min_temp_year = %d, average_year_temp = %d\n", max_temp_month, min_temp_month, amount_temp/size_meas);
   }   
}
/*void print_file_contents(const char *strfile, bool stat, char *month)
{
FILE *fp;
char str[15];
int znak1 = 1;
char znak2;
char znak3;
char znak4;
char znak5;
char znak6;

   fp=fopen(strfile, "r");
   {
     fgets(str, 126, fp);
      {
     printf("%s", str);
     printf("selstat = %d month = %s\n", stat, month);
     }
     fscanf(fp,"%d%s%s%s%s%s\n", &znak1, &znak2, &znak3, &znak4, &znak5, &znak6);
     printf("%d\n", znak1);
     printf("poluchi%s%s%s%s%s%s\n", znak1, znak2, znak3, znak4, znak5, znak6);
   }
  fclose(fp);

  } */
