### **Demonstration of Nested Recursion**

#### **1️⃣ Setting Up the Project**

- Uses the **same project** as before for the demonstration.
- Implements the **nested recursion function** previously discussed.

#### **2️⃣ Nested Recursion Function**

- Function **takes an integer `n`** as input.
- **Base Case:** If `n > 100`, return `n - 10`.
- **Recursive Case:** Otherwise, return `fun(n + 11)`.

#### **3️⃣ Running the Program**

- Calls the function in the `main()` function.
- Stores the result in a variable `r`.
- Prints the result of `r`.

#### **4️⃣ Output Observations**

| Input      | Output |
| ---------- | ------ |
| `fun(95)`  | `91`   |
| `fun(99)`  | `91`   |
| `fun(100)` | `91`   |
| `fun(200)` | `190`  |
| `fun(30)`  | `91`   |

- **Reasoning for `fun(30) → 91`**
  - 30 recursively increases to **101**.
  - When `n = 101`, it enters the base case: `101 - 10 = 91`.
  - Any value **less than 100 eventually leads to 91**.

#### **5️⃣ Debugging & Understanding**

- Encourages using a **debugger** for better understanding.
- Tracing the function helps visualize **how recursion unfolds**.
