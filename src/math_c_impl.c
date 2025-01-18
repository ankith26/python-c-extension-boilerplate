#include "math_c.h"

// Computes factorial given an long long input.
// Returns 0 on error, positive result on success.
unsigned long long c_factorial(long long n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * c_factorial(n - 1);
}
