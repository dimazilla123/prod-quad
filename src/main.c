#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "double_utils.h"

const char* USAGELINE = "Usage: %s a b c\n"
                       "Prints solutions of ax^2 + b^x + c = 0\n"
                       "a, b, c are written in floating point notation (10.02) or exponent form (1.02e1)\n";
char* progname = NULL;

void exit_with_userline()
{
    printf(USAGELINE, progname);
    exit(0);
}

int main(int argc, char *argv[])
{
    progname = argv[0];
    double a = 0, b = 0, c = 0, D = 0, x0 = 0, shift = 0;
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

    if (compare(a, 0) == 0)
        exit_with_userline();

    D = b * b - 4 * a * c;
    x0 = -b / (2 * a);
    switch (compare(0, D)) {
        case 0:
            printf("%f\n", x0);
            break;
        case 1:
            shift = sqrt(D) / (2 * a);
            printf("%f\n%f\n", x0 - shift, x0 + shift);
            break;
        case -1:
            break;
    }

    return 0;
}
