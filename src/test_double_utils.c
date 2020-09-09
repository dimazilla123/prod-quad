#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "double_utils.h"

int main(int argc, char const *argv[])
{
    double a[] = {1e9, 1e-9, 10, 22, 1.7, -20, -1e9, -1e-9};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
    {
        printf("%lf\n", a[i] / get_eps(a[i]));
        assert(fabs(a[i] / get_eps(a[i])) <= 10);
    }
    return 0;
}