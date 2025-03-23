### **1. Implementing the Tree Recursion Function**

- **Function Definition: `fun(n)`**
  - **Base Condition:** `if (n > 0)`
  - **Print n:** `printf(n)`
  - **Recursive Calls:** `fun(n-1)` twice
- **Calling the Function in `main()`**
  - **Example Call:** `fun(3)`

---

#### **2. Program Execution & Output**

- **Execution Flow:**
  - `fun(3)` → prints `3`, calls `fun(2)` twice
  - `fun(2)` → prints `2`, calls `fun(1)` twice
  - `fun(1)` → prints `1`, calls `fun(0)` twice
  - `fun(0)` → does not execute (base condition met)
- **Final Output:** `3 2 1 1 2 1 1`
- This output is generated due to the **recursive calls** and the function executing **twice for each decrement of `n`**.

---

#### **3. Debugging Process**

1. **First Function Call (`n = 3`)**

   - The function is first called with `n = 3`.
   - It prints `3`, then makes two recursive calls with `fun(2)`.

2. **Second Function Call (`n = 2`)**

   - The function is now called with `n = 2`.
   - It prints `2`, then calls `fun(1)` twice.

3. **Third Function Call (`n = 1`)**

   - The function is now called with `n = 1`.
   - It prints `1`, then calls `fun(0)` twice.

4. **Base Case (`n = 0`)**
   - When `n = 0`, the function does **not** execute further.
   - This marks the end of that specific recursive branch, and control returns to the previous call.
5. **Stack Activation Records**
   - **Total Function Calls Counted**
   - Calls are created & destroyed in LIFO order

---

#### **4. Recursion Flow Analysis**

- **First Recursive Call Path:** `3 → 2 → 1 → 0`
- **Backtracking:** Return to previous calls (`n = 1 → n = 2 → n = 3`)
- **Second Recursive Call Path:** Mirrors the first one

---

### **5. Understanding the Output and Recursion Flow**

- Each function call creates **two new recursive calls** (except at `n = 0`).
- The calls follow a **depth-first traversal**, meaning the leftmost recursive call completes first before moving to the right.
- The total recursive function calls can be counted based on the **expanding and shrinking call stack**.

---

### **6. Conclusion**

- **Tree recursion** results in **exponential function calls** since each call **branches into two more calls**.
- The stack grows and shrinks dynamically, with each function call creating a **new activation record** in memory.
