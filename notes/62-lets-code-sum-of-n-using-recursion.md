### **Finding the Sum of First N Natural Numbers**

#### **1. Introduction**

- Demonstrates two approaches: **Recursive** and **Iterative**
- Implements and tests both functions in C++
- Uses `N = 5` as an example (expected sum = 15)

---

#### **2. Recursive Approach**

- **Function Definition**:
  ```cpp
  int sum(int N) {
      if (N == 0) return 0;
      return sum(N - 1) + N;
  }
  ```
- **Explanation**:
  - If `N = 0`, return `0` (base case).
  - Otherwise, recursively call `sum(N-1)`, adding `N`.
- **Execution**:
  - Calls `sum(4)`, `sum(3)`, `sum(2)`, `sum(1)`, `sum(0)`.
  - Adds values while returning: `0 → 1 → 3 → 6 → 10 → 15`.
- **Time Complexity**: **O(N)**
- **Space Complexity**: **O(N)** (due to recursive stack)

---

#### **3. Iterative Approach**

- **Function Definition**:
  ```cpp
  int isum(int N) {
      int S = 0;
      for (int i = 1; i <= N; i++) {
          S += i;
      }
      return S;
  }
  ```
- **Explanation**:
  - Uses a loop to sum numbers from `1` to `N`.
  - Stores the sum in variable `S`.
- **Execution**:
  - **Loop Iterations**:
    - `i = 1, S = 1`
    - `i = 2, S = 3`
    - `i = 3, S = 6`
    - `i = 4, S = 10`
    - `i = 5, S = 15` (final result)
- **Time Complexity**: **O(N)**
- **Space Complexity**: **O(1)** (only a few variables used)

---

#### **4. Debugging & Execution**

- **Debugging Recursive Function**:
  - Observe recursive calls and stack behavior.
- **Debugging Iterative Function**:
  - Step through `for` loop execution.
  - Watch changes in variables `i` and `S`.

---

#### **5. Comparison: Recursive vs Iterative**

| Approach      | Pros                            | Cons                             |
| ------------- | ------------------------------- | -------------------------------- |
| **Recursive** | Simple to define mathematically | Uses extra memory (stack frames) |
| **Iterative** | Efficient in memory usage       | Requires explicit loop logic     |

---

#### **6. Conclusion**

- Both approaches yield the **same result**.
- Iterative is **preferred** due to lower space complexity.
- Recursive method is useful for understanding recursion fundamentals.
