### **Fibonacci Series Function (Mind Map)**

#### **1. Iterative Fibonacci Function**

- Function name: `fib(n)`
- Variables:
  - `t0 = 0`, `t1 = 1`, `S` (sum), `i` (loop counter)
- Steps:
  1.  Handle base case: If `n ≤ 1`, return `n`.
  2.  Use a `for` loop from `2` to `n`:
      - Calculate `S = t0 + t1`.
      - Update `t0 = t1`, `t1 = S`.
  3.  Return `S` as the nth Fibonacci number.

#### **2. Recursive Fibonacci Function**

- Function name: `rfib(n)`
- Base Case: If `n ≤ 1`, return `n`.
- Recursive Case:
  - Return `rfib(n-2) + rfib(n-1)`.
- Simple but leads to redundant calculations.

#### **3. Memoized Fibonacci Function**

- Function name: `mfib(n)`
- Uses **global array `F[10]`** to store computed values.
- **Initialization:**
  - Fill `F` with `-1` (to distinguish uncomputed values).
- Steps:
  1.  If `n ≤ 1`: Store `F[n] = n`, return `n`.
  2.  If `F[n-2]` is `-1`, compute `mfib(n-2)`, store result in `F[n-2]`.
  3.  If `F[n-1]` is `-1`, compute `mfib(n-1)`, store result in `F[n-1]`.
  4.  Store `F[n] = F[n-2] + F[n-1]`.
  5.  Return `F[n]`.
- **Efficiency:**
  - Reduces function calls significantly.
  - Stores values to prevent redundant calculations.

#### **4. Debugging & Function Calls Analysis**

- Used breakpoints to count function calls.
- Observed values stored in global array `F`.
- Verified optimized function calls (`mfib` only makes 6 calls for `mfib(5)`).
