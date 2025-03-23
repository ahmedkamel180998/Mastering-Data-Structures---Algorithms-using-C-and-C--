This transcript explains the behavior of **static variables in recursion** through a step-by-step breakdown. It begins by reviewing basic recursion concepts, such as **function calls, stack usage, and activation records**, and then introduces how **static variables affect recursion differently than local variables**.

### **1. Understanding Basic Recursion without Static Variables**

- A recursive function `fun(n)` is introduced:
  - If `n > 0`, the function calls itself with `fun(n-1)`, adding `n` to the result at return time.
  - If `n == 0`, it returns `0`.
- A **tracing tree** is used to explain how values are stored and calculated.
- Example execution for `fun(5)`:
  - Calls: `fun(5) → fun(4) → fun(3) → fun(2) → fun(1) → fun(0)`.
  - Returning process:
    - `fun(0) = 0`
    - `fun(1) = 0 + 1 = 1`
    - `fun(2) = 1 + 2 = 3`
    - `fun(3) = 3 + 3 = 6`
    - `fun(4) = 6 + 4 = 10`
    - `fun(5) = 10 + 5 = 15`
  - The **final result** is `15`.
- **Activation records in memory**:
  - Each recursive call creates a **new instance** of `n`, which is stored separately in the stack.

### **2. Introducing Static Variables in Recursion**

- **Modification:** A `static int x = 0` is introduced.
  - `x` is **incremented before calling** the function recursively.
  - Instead of adding `n`, the function now adds `x` during return time.
- **Key Differences with Static Variables:**
  - **Created only once** at the program's loading time.
  - Unlike `n`, **x is not reinitialized** for each recursive call.
  - Every function call **shares the same x value**.
- **Tracing Execution for `fun(5)` with Static `x`**:
  - Calls: `fun(5) → fun(4) → fun(3) → fun(2) → fun(1) → fun(0)`.
  - Values of `x` increment **only once** per call:
    - `x = 1 → 2 → 3 → 4 → 5`
  - Returning process:
    - `fun(0) = 0`
    - `fun(1) = 0 + 5 = 5`
    - `fun(2) = 5 + 5 = 10`
    - `fun(3) = 10 + 5 = 15`
    - `fun(4) = 15 + 5 = 20`
    - `fun(5) = 20 + 5 = 25`
  - The **final result** is `25` (instead of `15` in the previous version).

### **3. Comparison of Static and Local Variables**

- **Local Variables (`n`)**:
  - Each recursive call **creates a new copy** of `n`.
  - Values are **independent for each function call**.
- **Static Variables (`x`)**:
  - **Only one copy** is created and shared among all function calls.
  - **Retains its value across recursive calls**.

### **4. Equivalent Behavior with Global Variables**

- If `x` is **declared globally** instead of as a `static` variable:
  - The behavior **remains the same** since global variables also maintain a **single copy**.
- **Key takeaway:** Both **static and global variables** maintain a **single instance** throughout execution.

### **5. Conclusion**

- **Static variables are useful in recursion** when a value needs to persist across multiple recursive calls.
- They should **not be shown in tracing trees** as new instances in each call.
- They behave similarly to **global variables**, but remain limited in scope to their function.

In upcoming examples, the tutorial will continue using **recursive functions with static variables** to explore more applications.
