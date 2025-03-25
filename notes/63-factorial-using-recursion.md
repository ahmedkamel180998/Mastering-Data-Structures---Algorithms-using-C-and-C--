### **Finding Factorial of a Given Number**

This discussion explains how to compute the **factorial** of a number using both **recursion** and **iteration (loop)**. It also includes an analysis of memory usage and function calls.

---

## **1. Understanding Factorial**

- Factorial of a number **n** is the product of all positive integers from `1` to `n`.
- Represented as:  
  \[
  n! = 1 \times 2 \times 3 \times \dots \times n
  \]
- Example:  
  \[
  5! = 1 \times 2 \times 3 \times 4 \times 5 = 120
  \]
- **Special Cases**:
  - **0! = 1** (By definition)
  - **1! = 1**

---

## **2. Recursive Approach to Factorial**

### **Recursive Formula**

Factorial can be expressed recursively as:  
\[
n! = (n - 1)! \times n
\]
with the **base case**:  
\[
0! = 1
\]

### **Recursive Function in C++**

```cpp
int factorial(int n) {
    if (n == 0) return 1; // Base case
    return factorial(n - 1) * n; // Recursive case
}
```

### **Explanation**

- If `n == 0`, return `1` (base case).
- Otherwise, compute `factorial(n - 1)` and multiply it by `n`.
- The function calls itself until reaching `n == 0`.

### **Execution Steps for `factorial(5)`**

```
factorial(5) = factorial(4) * 5
factorial(4) = factorial(3) * 4
factorial(3) = factorial(2) * 3
factorial(2) = factorial(1) * 2
factorial(1) = factorial(0) * 1
factorial(0) = 1  (Base case)
```

Now, the recursion **unwinds**:

```
factorial(1) = 1 × 1 = 1
factorial(2) = 1 × 2 = 2
factorial(3) = 2 × 3 = 6
factorial(4) = 6 × 4 = 24
factorial(5) = 24 × 5 = 120
```

Final result: **120**.

### **Time Complexity & Space Complexity**

| Complexity Type      | Value                             |
| -------------------- | --------------------------------- |
| **Time Complexity**  | O(n)                              |
| **Space Complexity** | O(n) (stack frames for recursion) |

---

## **3. Iterative Approach to Factorial**

Instead of recursion, we can use a loop.

### **Iterative Function in C++**

```cpp
int iterativeFactorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

### **Explanation**

- Initializes `result = 1`.
- Loops from `1` to `n`, multiplying `result` by `i` at each step.
- Returns the final value after the loop completes.

### **Execution Steps for `iterativeFactorial(5)`**

```
result = 1
i = 1 → result = 1 * 1 = 1
i = 2 → result = 1 * 2 = 2
i = 3 → result = 2 * 3 = 6
i = 4 → result = 6 * 4 = 24
i = 5 → result = 24 * 5 = 120
```

Final result: **120**.

### **Time Complexity & Space Complexity**

| Complexity Type      | Value                       |
| -------------------- | --------------------------- |
| **Time Complexity**  | O(n)                        |
| **Space Complexity** | O(1) (only a few variables) |

---

## **4. Comparison: Recursive vs Iterative Approach**

| Approach      | Pros                            | Cons                                 |
| ------------- | ------------------------------- | ------------------------------------ |
| **Recursive** | Matches mathematical definition | Uses extra memory (O(n) stack calls) |
| **Iterative** | Efficient (O(1) space)          | Requires explicit loop logic         |

### **Key Observations**

- **Recursive solution is easier to define but inefficient in memory usage**.
- **Iterative solution is preferred for performance**.
- **Both methods have the same time complexity O(n)**, but recursion uses extra memory due to function calls.

---

## **5. Function Call Analysis (Recursion)**

- Each function call consumes **stack space**.
- For `factorial(5)`, **6 function calls** are made (including `factorial(0)`).
- Stack grows **proportionally to `n`** → **O(n) space**.

---

## **6. Conclusion**

- **Factorial can be computed using both recursion and iteration.**
- **Recursive approach is intuitive but consumes extra memory.**
- **Iterative approach is more memory-efficient.**
- **For large values of `n`, use the iterative approach to avoid stack overflow.**
