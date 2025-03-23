### **Detailed Summary of Nested Recursion**

#### **1️⃣ What is Nested Recursion?**

- **Definition:**
  - In nested recursion, a recursive function calls itself **with a parameter that is another recursive call**.
  - This means that before making the actual recursive call, the function must **evaluate** another recursive call.
  - It leads to deep recursion trees as each function call waits for an inner function call to be resolved first.

---

#### **2️⃣ Example of Nested Recursion**

- **Function Definition:**
  ```cpp
  int fun(int n) {
      if (n > 100)
          return n - 10;
      return fun(fun(n + 11));
  }
  ```
  - If `n > 100`, return `n - 10` directly (**Base Case**).
  - Otherwise, the function calls itself **twice**:
    - First, `fun(n + 11)` is calculated.
    - Then, the result is used as the parameter in another recursive call `fun(fun(n + 11))`.

---

#### **3️⃣ Step-by-Step Execution of `fun(95)`**

- **Initial Call:** `fun(95)`
  - `95` is not greater than `100`, so it enters the `else` block:
  - Calls `fun(fun(95 + 11))` → `fun(fun(106))`

##### **Step 1: Compute `fun(106)`**

- `106 > 100`, so return `106 - 10 = 96`
- Now, replace `fun(106)` with `96`
- The function call becomes: `fun(96)`

##### **Step 2: Compute `fun(96)`**

- `96` is not greater than `100`, so it calls `fun(fun(96 + 11))`
- This becomes: `fun(fun(107))`

##### **Step 3: Compute `fun(107)`**

- `107 > 100`, so return `107 - 10 = 97`
- Replace `fun(107)` with `97`
- The function call becomes: `fun(97)`

##### **Step 4: Compute `fun(97)`**

- `97` is not greater than `100`, so it calls `fun(fun(97 + 11))`
- This becomes: `fun(fun(108))`

##### **Step 5: Compute `fun(108)`**

- `108 > 100`, so return `108 - 10 = 98`
- Replace `fun(108)` with `98`
- The function call becomes: `fun(98)`

##### **Step 6: Compute `fun(98)`**

- `98` is not greater than `100`, so it calls `fun(fun(98 + 11))`
- This becomes: `fun(fun(109))`

##### **Step 7: Compute `fun(109)`**

- `109 > 100`, so return `109 - 10 = 99`
- Replace `fun(109)` with `99`
- The function call becomes: `fun(99)`

##### **Step 8: Compute `fun(99)`**

- `99` is not greater than `100`, so it calls `fun(fun(99 + 11))`
- This becomes: `fun(fun(110))`

##### **Step 9: Compute `fun(110)`**

- `110 > 100`, so return `110 - 10 = 100`
- Replace `fun(110)` with `100`
- The function call becomes: `fun(100)`

##### **Step 10: Compute `fun(100)`**

- `100` is **not greater** than `100`, so it calls `fun(fun(100 + 11))`
- This becomes: `fun(fun(111))`

##### **Step 11: Compute `fun(111)`**

- `111 > 100`, so return `111 - 10 = 101`
- Replace `fun(111)` with `101`
- The function call becomes: `fun(101)`

##### **Step 12: Compute `fun(101)`**

- `101 > 100`, so return `101 - 10 = 91`
- Replace `fun(101)` with `91`

##### **Final Step:**

- Now, `fun(95) = fun(96) = fun(97) = ... = fun(101) = 91`
- So, **`fun(95) = 91`**

---

#### **4️⃣ Key Observations**

- The function call expands like a **recursion tree**.
- Each function call **waits for the inner function call result** before proceeding.
- The recursion goes **deeper** before returning values back up.
- The base case is reached **only when `n > 100`**.
- The final result for `fun(95)` is **91**.

---

#### **5️⃣ Summary of Nested Recursion**

| Aspect                  | Description                                                                |
| ----------------------- | -------------------------------------------------------------------------- |
| **Concept**             | Function calls itself with another recursive function call as a parameter. |
| **Base Case**           | When `n > 100`, return `n - 10`.                                           |
| **Recursive Case**      | Calls `fun(fun(n + 11))`.                                                  |
| **Execution Order**     | Innermost function executes first, then returns results to outer calls.    |
| **Key Challenge**       | Requires evaluating inner recursion **before** the outer call can proceed. |
| **Output of `fun(95)`** | `91`                                                                       |

---

### ✅ **Conclusion**

- **Nested recursion is a complex form of recursion** where function calls depend on inner function results.
- It generates **a deeply recursive execution tree**.
- Tracing it manually is challenging but helps understand **recursive dependencies**.
- **Practical Usage:** Nested recursion is not commonly used in real-world applications but helps in **theoretical understanding of recursion concepts**.
