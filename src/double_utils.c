#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include "double_utils.h"

// TODO: extract exponent from format
double get_eps(double x)
{
    const double STEP = 10;
    x = fabs(x);
    double ans = 1;
    if (x == 0)
        return ans;
    while (x < 1)
    {
        ans /= STEP;
        x *= STEP;
    }
    while (x > STEP)
    {
        ans *= STEP;
        x /= STEP;
    }
    return ans;
}

int compare(double a, double b)
{
    double eps = get_eps(b - a);
    if (2 * (b - a) >= eps)
        return 1;
    if (2 * (a - b) >= eps)
        return -1;
    return 0;
}

bool convertdouble(const char* s, double *out)
{
    return sscanf(s, "%lg", out) == 1;
}

double random_double()
{
    return (rand() % 2 == 0 ? -1 : 1) * (double)rand() / RAND_MAX;
}