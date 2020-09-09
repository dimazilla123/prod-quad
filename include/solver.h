#ifndef SOLVER_H
#define SOLVER_H

#define INFINITE_SOLUTIONS -1
#define ERROR_DURING_SOLUTION -2

/*
 * @fn int solve(double a, double b, double c, double* x1, double* x2)
 * @brief Solves quadratic equation
 *
 * Solves equation ax^2+bx+c = 0, writes answers to x1 and x2, return special code or number of solutions
 * @param a a coefficient
 * @param b b coefficient
 * @param c c coefficient
 * @param x1 pointer to the first root storage
 * @param x2 pointer to the second root storage
 *
 * @return INFINITE_SOLUTIONS if the equation has infinite count of soulutions, ERROR_DURING_SOLUTION if an error
 * has occured during computations, otherwise count of soulutions (0, 1 or 2)
 */

int solve(double a, double b, double c, double* x1, double* x2);

#endif