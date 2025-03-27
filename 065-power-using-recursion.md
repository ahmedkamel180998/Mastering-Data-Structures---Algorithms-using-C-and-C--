```c
int power(int m, int n) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= m;
        }
        m *= m;
        n /= 2;
    }
    return result;
}
```

This version:

1. Initializes `result` to 1 (the identity for multiplication)
2. While `n` is positive:
   - If `n` is odd, multiplies the result by the current `m` value
   - Squares `m` (just like the recursive version does)
   - Halves `n` (using integer division)
3. Returns the final result when `n` reaches 0

This is an efficient O(log n) implementation of exponentiation using the "exponentiation by squaring" method, just like the recursive version using while loop.
