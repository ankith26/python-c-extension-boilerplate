def factorial(n):
    if n < 0:
        raise ValueError("Negative input not allowed for factorial")

    if n == 0 or n == 1:
        return 1

    return n * factorial(n - 1)
