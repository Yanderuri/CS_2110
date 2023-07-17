#ifndef SUPPORT_H
#define SUPPORT_H


#include <stdlib.h>
#include <string.h>

#define PI 3.14159265


int itoa(int value, char *sp, int radix);
void score_string_maker(char * results, int score);
double sine_taylor(double x);
#endif