#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "double_utils.h"
#include "solver.h"

const char* USAGELINE = "Usage: %s a b c\n"
                       "Prints solutions of ax^2 + b^x + c = 0\n"
                       "a, b, c are written in floating point notation (e.g. 10.02) or exponent form (e.g. 1.02e1)\n";
char* progname = NULL;

void exit_with_userline()
{
    assert(progname != NULL);
    printf(USAGELINE, progname);
    exit(0);
}

int main(int argc, char *argv[])
{
    double a = 0, b = 0, c = 0;
    double xs[2] = {0, 0};
    progname = argv[0];

    if (argc < 4)
        exit_with_userline();
    if (!convertdouble(argv[1], &a))
    {
        printf("Cannot convert a to double!\n");
        exit_with_userline();
    }
    if (!convertdouble(argv[2], &b))
    {
        printf("Cannot convert b to double!\n");
        exit_with_userline();
    }
    if (!convertdouble(argv[3], &c))
    {
        printf("Cannot convert c to double!\n");
        exit_with_userline();
    }

    int solutions = solve(a, b, c, xs, xs + 1);
    if (solutions == INFINITE_SOLUTIONS)
        printf("INF\n");
    else if (solutions == ERROR_DURING_SOLUTION)
        printf("An error has occured\n");
    else
    {
        for (int i = 0; i < solutions; ++i)
            printf("%le\n", xs[i]);
    }

    return 0;
}