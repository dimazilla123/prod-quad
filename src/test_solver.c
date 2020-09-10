#include <stdio.h>
#include "solver.h"
#include "double_utils.h"
#include "bool.h"

bool check(double test[6])
{
    double xs[2] = {0, 0};
    int solutions = solve(test[0], test[1], test[2], xs, xs + 1);
    if (solutions == ERROR_DURING_SOLUTION)
        return false;
    if (solutions == INFINITE_SOLUTIONS)
    {
        return compare(test[0], 0) == 0
            && compare(test[1], 0) == 0
            && compare(test[2], 0) == 0;
    }
    for (int i = 0; i < solutions; ++i)
        if (compare(test[0] * xs[i] * xs[i] + test[1] * xs[i] + test[2], 0) != 0)
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
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
        if (!check(tests[i]))
        {
            printf("Error at test %d\n", i);
            return -1;
        }
    return 0;
}