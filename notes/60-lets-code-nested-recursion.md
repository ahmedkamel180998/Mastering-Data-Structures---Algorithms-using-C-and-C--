### **Nested Recursion in C++**

#### 🟢 **1. Concept of Nested Recursion**

- A function calls itself with **another recursive call** as its argument.
- The **inner recursive call** must resolve first before the **outer recursive call** can proceed.

#### 🟠 **2. Code Implementation**

- Function Definition:
  ```cpp
  int fun(int n) {
      if (n > 100)
          return n - 10;
      return fun(fun(n + 11)); // Nested recursion
  }
  ```
- **Main Function**:
  ```cpp
  int main() {
      int r = fun(95);
      printf("%d\n", r);
      return 0;
  }
  ```
- Calls function `fun(n)` with different values: **95, 99, 100, 200, 30**.

#### 🔵 **3. Tracing Function Call (`fun(95)`)**

- `fun(95)` → Calls `fun(fun(106))`
- `fun(106)` → Returns **96** (`106 - 10`)
- `fun(96)` → Calls `fun(fun(107))`
- `fun(107)` → Returns **97** (`107 - 10`)
- This pattern continues until reaching **fun(101) → 91**.
- **Final result for any input ≤ 100 is 91.**

#### 🟣 **4. Observations**

- **If `n > 100`** → Directly returns `n - 10`.
- **If `n ≤ 100`** → Recursion expands until `n > 100` is reached.
- **All values ≤ 100 return 91** after recursion completes.

#### 🔴 **5. Conclusion**

- **Nested recursion leads to deep recursion trees.**
- **Tracing the function manually can be complex.**
- **Debugging tools help visualize recursion flow.**
- **Efficient but not optimal for large values due to recursion depth.**
