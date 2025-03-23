### **Detailed Summary: Tree Recursion Explained**

In this lesson, the concept of **Tree Recursion** is explained by first comparing it to **Linear Recursion**. The explanation includes tracing the execution, analyzing stack usage, and determining time and space complexity.

---

### **Linear Recursion vs. Tree Recursion**

1. **Linear Recursion**:

   - A function that calls itself only **once** in its recursive definition.
   - The previously covered topics include **Head Recursion** and **Tail Recursion**.
   - Some functions have processing before and after the recursive call but do not fit precisely into head or tail recursion.

2. **Tree Recursion**:
   - A function calls itself **more than once** in its recursive definition.
   - If a function calls itself twice, it forms a **binary recursion tree**.
   - If a function calls itself more than twice, it expands further into a tree-like structure.

---

### **Example of Tree Recursion (Pseudocode)**

```cpp
void fun(int n) {
    if (n > 0) {
        cout << n << " ";  // Print the value of n
        fun(n - 1);        // First recursive call
        fun(n - 1);        // Second recursive call
    }
}
```

#### **Tracing the Execution (for fun(3)):**

When calling `fun(3)`, it generates the following sequence of recursive calls:

```
fun(3)
├── fun(2)
│   ├── fun(1)
│   │   ├── fun(0)   (Terminates)
│   │   ├── fun(0)   (Terminates)
│   ├── fun(1)
│   │   ├── fun(0)   (Terminates)
│   │   ├── fun(0)   (Terminates)
├── fun(2)
│   ├── fun(1)
│   │   ├── fun(0)   (Terminates)
│   │   ├── fun(0)   (Terminates)
│   ├── fun(1)
│   │   ├── fun(0)   (Terminates)
│   │   ├── fun(0)   (Terminates)
```

#### **Output of fun(3):**

```
3 2 1 1 2 1 1
```

---

### **Stack Usage Analysis**

Each recursive call creates an **activation record** (AR) in the stack. The maximum number of activation records in the stack at any point represents the **space complexity**.

1. **Activation Record Creation:**

   - Whenever `fun(n)` is called, a new AR is created.
   - For `n = 3`, the deepest stack depth reaches **4** (corresponding to `n+1` levels).

2. **Stack Growth and Deletion:**

   - As soon as `fun(0)` is reached, the function terminates, and the corresponding AR is **deleted**.
   - After each deletion, the function **returns to its previous activation record**.

3. **Total Number of Calls:**
   - The total calls made follow the pattern:
     ```
     1 + 2 + 4 + 8 = 15 (for n=3)
     ```
   - This forms a **geometric progression** with a total count of:
     ```
     2^(n+1) - 1
     ```
   - Hence, for general `n`, the number of calls is **O(2^n)**.

---

### **Time Complexity Analysis**

1. **Each function call makes two recursive calls:**
   ```
   T(n) = 2T(n-1) + O(1)
   ```
   - The number of calls follows the series:
     ```
     2^0 + 2^1 + 2^2 + ... + 2^n = 2^(n+1) - 1
     ```
   - Therefore, the **time complexity is O(2^n)**.

---

### **Space Complexity Analysis**

1. **Space required depends on the height of the recursion tree.**
2. **Stack height = depth of recursion tree = O(n).**
3. **Space complexity = O(n).**

---

### **Conclusion**

- **Tree recursion** occurs when a function calls itself **more than once** in its recursive case.
- The **time complexity** for this function is **O(2^n)** due to the exponential growth of function calls.
- The **space complexity** is **O(n)**, determined by the recursion depth.
- The maximum number of function calls can be determined using a **geometric series** formula.

This explanation provides a clear understanding of **Tree Recursion** and how it differs from **Linear Recursion**, along with practical insights into **stack usage and complexity analysis**.
