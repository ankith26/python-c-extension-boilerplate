def factorial(n):
    if n < 0:
        raise ValueError("Negative input not allowed for factorial")

    if n == 0 or n == 1:
        return 1

    return n * factorial(n - 1)


def fibsequence(n):
    if n < 0:
        raise ValueError("Negative input not allowed")

    # Initialize the Fibonacci sequence
    fib_sequence = []
    a, b = 0, 1

    for _ in range(n):
        fib_sequence.append(a)
        temp = a + b
        a = b
        b = temp

    return fib_sequence
