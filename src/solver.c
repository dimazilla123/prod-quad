#include <stddef.h>
#include <math.h>
#include "solver.h"
#include "double_utils.h"

int solve(double a, double b, double c, double* x1, double* x2)
{
    if (x1 == NULL || x2 == NULL)
        return ERROR_DURING_SOLUTION;
    if (compare(0, a) == 0)
    {
        if (compare(0, b) == 0)
            return (compare(0, c) == 0 ? INFINITE_SOLUTIONS : 0);
        *x1 = -c / b;
        return 1;
    }
    double D = b * b - 4 * a * c;
    double x0 = -b / (2 * a);
    switch (compare(0, D))
    {
        case -1:
            return 0;
        case 0:
        {
            *x1 = *x2 = x0;
            return 1;
        }
        case 1:
        {
            D = fabs(sqrt(D) / (2 * a));
            *x1 = x0 - D;
            *x2 = x0 + D;
            return 2;
        }
    }
}