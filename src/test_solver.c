#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solver.h"
#include "double_utils.h"
#include "bool.h"

#define max(a, b) (a < b ? b : a)
#define min(a, b) (a < b ? b : a)

bool check(double a, double b, double c)
{
    double xs[2] = {0, 0};
    int solutions = solve(a, b, c, xs, xs + 1);
    if (solutions == ERROR_DURING_SOLUTION)
        return false;
    if (solutions == INFINITE_SOLUTIONS)
    {
        return compare(a, 0) == 0
            && compare(b, 0) == 0
            && compare(c, 0) == 0;
    }
    for (int i = 0; i < solutions; ++i)
    {
        double min_eps = min(min(get_eps(a),
                                 get_eps(b)),
                             min(get_eps(c),
                                 get_eps(xs[i])));
        double v =a * xs[i] * xs[i] + b * xs[i] + c;
        if (fabs(v) / min_eps >= 1)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s seed tests_count\n", argv[0]);
        return 0;
    }
    srand(atoi(argv[1]));
    int test_cnt = atoi(argv[2]);
    for (int i = 0; i < test_cnt; ++i)
    {
        double a = random_double(),
               b = random_double(),
               c = random_double();
               if (!check(a, b, c))
               {
                   printf("Error at test %d\n", i);
                   printf("a b c = %lf %lf %lf\n", a, b, c);
                   return 0;
               }
    }
    double tests[][6] =
    {
    //      a     b     c     solutions_count   x1  x2
        {   1,   -2,    1,                  1,   1, 1},
        {   1,   -3,    2,                  2,   1, 2},
        {   1,   -2,    2,                  0,   0, 0},
        { 1e9, -2e9,  1e9,                  1,   1, 1},
        { 1e9, -2e9,  1e9,                  1,   1, 1},
        {   0, -2e9,  1e9,                  1, 0.5, 1},
        {   0,    0,    1,                  0,   0, 0},
        {   0,    0,    0, INFINITE_SOLUTIONS,   0, 0},
    };
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
        if (!check(tests[i][0], tests[i][1], tests[i][2]))
        {
            printf("Error at preset test %d\n", i);
            return -1;
        }
    return 0;
}