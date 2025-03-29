### **Fibonacci Series and its Implementation**

The lecture explains the Fibonacci series, its recursive definition, iterative and recursive implementations, and time complexity analysis. It introduces **memoization** to optimize the recursive function.

---

## **1. Introduction to Fibonacci Series**

- The Fibonacci series starts as: **0, 1, 1, 2, 3, 5, 8, 13, ...**
- Each term (after the first two) is obtained by summing the previous two terms:
  \[
  F(n) = F(n-1) + F(n-2) \quad \text{for } n > 1
  \]
- Base cases:
  - \( F(0) = 0 \)
  - \( F(1) = 1 \)

---

## **2. Recursive Definition and Implementation**

- A recursive function for Fibonacci follows the recurrence relation:
  ```cpp
  int fib(int n) {
      if (n <= 1)
          return n;
      return fib(n - 1) + fib(n - 2);
  }
  ```
- **Drawbacks of recursion:**
  - **Excessive function calls:** The same values are computed multiple times.
  - **Exponential time complexity:** \( O(2^N) \).

---

## **3. Iterative Implementation**

- Instead of recursion, a loop can be used:
  ```cpp
  int fib(int n) {
      if (n <= 1)
          return n;
      int t0 = 0, t1 = 1, s;
      for (int i = 2; i <= n; i++) {
          s = t0 + t1;
          t0 = t1;
          t1 = s;
      }
      return s;
  }
  ```
- **Time complexity:** \( O(N) \), which is significantly better than \( O(2^N) \).

---

## **4. Recursive Function Call Analysis**

- The recursion tree for **fib(5)** shows repeated function calls:
  ```
                      fib(5)
                   /        \
               fib(4)       fib(3)
              /      \      /      \
          fib(3)   fib(2) fib(2)  fib(1)
         /     \    /   \
      fib(2) fib(1) fib(1) fib(0)
     /    \
  fib(1) fib(0)
  ```
- **Repeated calculations:** \( fib(3) \) is computed multiple times.
- **Exponential growth in calls:** For **fib(5)**, there are **15 calls**.

---

## **5. Time Complexity of Recursive Fibonacci**

- The recurrence relation:
  \[
  T(n) = T(n-1) + T(n-2) + O(1)
  \]
- The number of function calls grows **exponentially**, leading to a time complexity of:
  \[
  O(2^N)
  \]
- This makes the recursive function **very slow** for large values of \( N \).

---

## **6. Optimizing Recursion with Memoization**

- **Problem in recursive Fibonacci:** Excessive repeated calculations.
- **Solution:** Store previously computed values in an **array** (memoization).
- **Implementation using an array:**

  ```cpp
  int F[100];  // Array initialized with -1 in main()

  int fib(int n) {
      if (n <= 1) {
          F[n] = n;
          return n;
      }
      if (F[n-2] == -1)
          F[n-2] = fib(n-2);
      if (F[n-1] == -1)
          F[n-1] = fib(n-1);
      return F[n-2] + F[n-1];
  }
  ```

- **How Memoization Works:**
  - If **F(n)** is already computed, reuse it instead of recalculating.
  - This avoids redundant recursive calls.
- **Time complexity:** \( O(N) \), much faster than \( O(2^N) \).

---

## **7. Final Comparison of Fibonacci Implementations**

| Approach        | Time Complexity | Space Complexity   | Notes                                    |
| --------------- | --------------- | ------------------ | ---------------------------------------- |
| **Recursive**   | \( O(2^N) \)    | \( O(N) \) (stack) | Very slow                                |
| **Iterative**   | \( O(N) \)      | \( O(1) \)         | Efficient, best for small values         |
| **Memoization** | \( O(N) \)      | \( O(N) \)         | Faster recursion, avoids redundant calls |

---

## **8. Conclusion**

- **Recursive Fibonacci is inefficient** due to excessive calls.
- **Iterative Fibonacci is efficient** and recommended when memory is limited.
- **Memoization improves recursive Fibonacci** by storing previously computed values.
- **Key takeaway:** Memoization reduces exponential time complexity to linear time, making recursion practical for large inputs.
