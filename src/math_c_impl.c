#include "math_c.h"
#include "stdlib.h"

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

long long *c_fibsequence(long long n)
{
    // Handle edge case
    if (n <= 0)
    {
        return NULL;
    }

    // Allocate memory for the Fibonacci numbers
    unsigned long long *fib_sequence = (unsigned long long *)malloc(n * sizeof(unsigned long long));
    if (!fib_sequence)
    {
        return NULL;
    }

    unsigned long long a = 0, b = 1, temp;

    for (long long i = 0; i < n; i++)
    {
        fib_sequence[i] = a;
        temp = a + b;
        a = b;
        b = temp;
    }

    return fib_sequence;
}
