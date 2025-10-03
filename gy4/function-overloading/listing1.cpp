#include <stdio.h>

/* C++ */
float        abs(float x)        { return x < 0 ? -x : x; }
double       abs(double x)       { return x < 0 ? -x : x; }
long double  abs(long double x)  { return x < 0 ? -x : x; }
unsigned int abs(unsigned int x) { return x; }

/* C
#include <math.h>

double fabs(double x);
float fabsf(float x);
long double fabsl(long double x);

#include <stdlib.h>

int abs(int j);
long labs(long j);
long long llabs(long long j)
*/
