### **Main Topic: Finding Factorial of a Number**

📌 **1. Introduction**

- Function to compute factorial
- Two approaches: **Recursive & Iterative**

---

📌 **2. Recursive Function**

- **Definition:**
  - If `n == 0`, return `1` (base case).
  - Else, return `factorial(n-1) * n`.
- **Example:**
  - `factorial(5) = 5 * factorial(4) = 120`
- **Implementation:**
  ```cpp
  int factorial(int n) {
      if (n == 0) return 1;
      return factorial(n - 1) * n;
  }
  ```
- **Issues with Negative Input:**
  - If `n < 0`, results in **infinite recursion**.
  - Causes **stack overflow** due to excessive function calls.
  - **Solution:** Add a condition to prevent recursion for `n < 0`.

---

📌 **3. Iterative Function**

- **Definition:** Uses a `for` loop instead of recursion.
- **Implementation:**
  ```cpp
  int iterativeFactorial(int n) {
      int f = 1;
      for (int i = 1; i <= n; i++) {
          f *= i;
      }
      return f;
  }
  ```
- **Execution Steps for `factorial(5)`**:
  - `i = 1 → f = 1`
  - `i = 2 → f = 2`
  - `i = 3 → f = 6`
  - `i = 4 → f = 24`
  - `i = 5 → f = 120`
- **Debugging Observations:**
  - Values of `f` and `i` change step by step.
  - Function stops when `i > n` and returns `f`.

---

📌 **4. Comparison: Recursive vs Iterative**  
| Approach | Pros | Cons |
|----------|------|------|
| **Recursive** | Matches mathematical definition | Uses more memory (O(n) stack calls) |
| **Iterative** | Efficient in space (O(1)) | Requires explicit loop logic |

✅ **Conclusion:**

- **Recursion** is intuitive but can lead to **stack overflow**.
- **Iteration** is more efficient and avoids memory issues.
