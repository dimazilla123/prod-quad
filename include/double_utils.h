#ifndef DOUBLE_UTILS_H
#define DOUBLE_UTILS_H

/*!
 * @file Contains some unilites to work with doubles
 */

#include "bool.h"

/*!
 * @fn int compare(double a, double b)
 * @brief Compare doubles
 *
 * Compares two doubles with selected epsilon.
 *
 * @param a first double
 * @param b second double
 *
 * @return 0 if \f$|a - b| \in \epsilon\f$, 1 if \f$b - a \in \epsilon\f$ and -1 if \f$a - b \in \epsilon\f$
 */

int compare(double a, double b);

/*!
 * @fn bool convertdouble(const char* s, double *out)
 * @brief Convert string to double or tell that format is wrong
 *
 * @param s pointer to not NULL string
 * @param out pointer to double to write result
 * @return true if convertion succseed, false otherwise 
 */

bool convertdouble(const char* s, double *out);

/*!
 * @fn double get_eps(double x)
 * @brief Get exponent in standart number form
 *
 * @param x real number
 * @return STEP^y, that STEP >= x * STEP^y
 */

double get_eps(double x);

#endif