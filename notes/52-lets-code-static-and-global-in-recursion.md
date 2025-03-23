### **1. Introduction to Static and Global Variables in Recursion**

The demonstration starts with an explanation of how static and global variables behave in recursive functions. A new command-line project named **Static Global** is created.

**Code Snippet (Project Setup & Function Definition):**

```cpp
#include <iostream>
using namespace std;

int fun(int n) {
    if (n > 0)
        return fun(n - 1) + n;
    else
        return 0;
}

int main() {
    int r;
    r = fun(5);
    printf("%d\n", r);  // Expected output: 15
    return 0;
}
```

**Explanation:**

- The function calculates the sum of the first `n` natural numbers.
- A call to `fun(5)` returns `15`, which is the expected output.

---

### **2. Modifying the Function to Use a Static Variable**

The function is modified to include a **static variable** `x`, which is incremented before the recursive call. The static variable maintains its value across function calls.

**Modified Code (Using Static Variable):**

```cpp
#include <iostream>
using namespace std;

int fun(int n) {
    static int x = 0;
    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    } else {
        return 0;
    }
}

int main() {
    int r;
    r = fun(5);
    printf("%d\n", r);  // Expected output: 25
    return 0;
}
```

**Explanation:**

- The static variable `x` is incremented at each call.
- Since `x` maintains its value across calls, it remains `5` when returning.
- The sum is computed differently than before, leading to an output of **25**.

---

### **3. Debugging the Function with Static Variables**

The function is debugged step-by-step, showing that `x` increments with each call and maintains its value while unwinding the recursion.

**Key Observations in Debugging:**

- `x` starts at `0`.
- On each recursive call, `x` increments (`1, 2, 3, 4, 5`).
- At `n = 0`, recursion stops and begins returning values.
- The final result is computed using the **same** value of `x` for each step while returning, leading to **25**.

---

### **4. Modifying the Function to Use a Global Variable**

Instead of using a static variable, `x` is declared as a **global variable** outside the function.

**Modified Code (Using Global Variable):**

```cpp
#include <iostream>
using namespace std;

int x = 0;  // Global variable

int fun(int n) {
    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    } else {
        return 0;
    }
}

int main() {
    int r;
    r = fun(5);
    printf("%d\n", r);  // Expected output: 25
    return 0;
}
```

**Explanation:**

- `x` is now globally defined outside the function.
- The behavior remains **identical** to using a static variable.

---

### **5. Calling the Function Twice**

The function is called **twice** to observe the effect of `x` being a persistent variable.

**Updated Code:**

```cpp
int main() {
    int r;
    r = fun(5);
    printf("%d\n", r);  // First call: 25

    r = fun(5);
    printf("%d\n", r);  // Second call: 50

    return 0;
}
```

**Explanation:**

- **First Call:**
  - `x` increments from `0` to `5`, giving a result of **25**.
- **Second Call:**
  - Since `x` retains its value (`5` from the first call), it starts from `5` instead of `0`.
  - The same recursion runs, making `x` reach `10`, leading to **50** as output.

---

### **6. Conclusion: When to Use Static or Global Variables**

- **Static variables** retain values across function calls but are confined to the function scope.
- **Global variables** are accessible by all functions and persist across multiple function calls.
- Recursive functions can sometimes be rewritten using static/global variables when necessary.

---

### **Final Thoughts**

The demonstration highlights the importance of handling static and global variables correctly in recursion. The key takeaway is that static variables are **function-scoped but persistent**, while global variables affect multiple calls beyond a single execution.
