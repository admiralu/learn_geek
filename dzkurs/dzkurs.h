#pragma once

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

typedef struct measurements data_t;

void init_data2(int size_meas, data_t *ukaz_meas, const char *strfile, int number_month);
