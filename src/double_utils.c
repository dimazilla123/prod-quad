#include <stdio.h>
#include <float.h>
#include <math.h>
#include "double_utils.h"

static const double EPS = 1e-5;

double get_eps(double x)
{
    x = fabs(x);
    double ans = 1;
    if (x == 0)
        return ans;
    while (x < 1)
    {
        ans /= 10;
        x *= 10;
    }
    while (x > 10)
    {
        ans *= 10;
        x /= 10;
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