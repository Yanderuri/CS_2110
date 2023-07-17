#include "support.h"
// Attributions: https://stackoverflow.com/questions/3440726/what-is-the-proper-way-of-implementing-a-good-itoa-function
int itoa(int value, char *sp, int radix)
{
    char tmp[16];// be careful with the length of the buffer
    char *tp = tmp;
    int i;
    unsigned v;
    int sign = (radix == 10 && value < 0);    
    if (sign)
        v = -value;
    else
        v = (unsigned)value;
    while (v || tp == tmp)
    {
        i = v % radix;
        v /= radix;
        if (i < 10)
          *tp++ = i+'0';
        else
          *tp++ = i + 'a' - 10;
    }
    int len = tp - tmp;
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }
    while (tp > tmp)
        *sp++ = *--tp;
    *sp = 0;
    return len;
}

void score_string_maker(char * results, int score){
	char * itoa_score_string;
	if ((itoa_score_string = malloc(3)) == NULL)
	{
		return;
	}
	itoa(score, itoa_score_string, 10);
	strncpy(results, "Score: ", 8);
    strncat(results, itoa_score_string, 3);
    free(itoa_score_string);
}
// Attributions: https://codereview.stackexchange.com/questions/5211/sine-function-in-c-c
double sine_taylor(double x)
{
    // Reduce the period to [-pi/2, pi/2]
    if (x <= -PI / 2){
        while (x <= -PI / 2){
            x += PI / 2;
        }
    }
    else if (x > PI / 2){
        while (x > PI / 2){
            x -= PI / 2;
        }
    }
    // useful to pre-calculate
    double x2 = x*x;
    double x4 = x2*x2;

    // Calculate the terms
    // As long as abs(x) < sqrt(6), which is 2.45, all terms will be positive.
    // Values outside this range should be reduced to [-pi/2, pi/2] anyway for accuracy.
    // Some care has to be given to the factorials.
    // They can be pre-calculated by the compiler,
    // but the value for the higher ones will exceed the storage capacity of int.
    // so force the compiler to use unsigned long longs (if available) or doubles.
    double t1 = x * (1.0 - x2 / (2*3));
    double x5 = x * x4;
    double t2 = x5 * (1.0 - x2 / (6*7)) / (1.0* 2*3*4*5);
    double x9 = x5 * x4;
    double t3 = x9 * (1.0 - x2 / (10*11)) / (1.0* 2*3*4*5*6*7*8*9);
    double x13 = x9 * x4;
    double t4 = x13 * (1.0 - x2 / (14*15)) / (1.0* 2*3*4*5*6*7*8*9*10*11*12*13);
    // add some more if your accuracy requires them.
    // But remember that x is smaller than 2, and the factorial grows very fast
    // so I doubt that 2^17 / 17! will add anything.
    // Even t4 might already be too small to matter when compared with t1.

    // Sum backwards
    double result = t4;
    result += t3;
    result += t2;
    result += t1;

    return result;
}