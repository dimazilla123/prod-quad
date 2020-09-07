#include <stdio.h>
#include "double_utils.h"

int compare(double a, double b)
{
    if (2 * (b - a) >= EPS)
        return 1;
    if (2 * (a - b) >= EPS)
        return -1;
    return 0;
}

bool convertdouble(const char* s, double *out)
{
    return sscanf(s, "%lg", out) == 1;
}