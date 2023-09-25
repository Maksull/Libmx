#include "libmx.h"

double mx_pow(double n, unsigned int pow)
{
    double result = 1.0;
    while (pow > 0) {
        if (pow % 2 == 1) {
            result *= n;
        }
        n *= n;
        pow /= 2;
    }
    return result;
}
