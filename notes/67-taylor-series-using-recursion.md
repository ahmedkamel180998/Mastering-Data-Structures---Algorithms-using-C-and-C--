### **📌 Overview**

- The video explains how to implement **Taylor Series** using **recursion**.
- The focus is on deriving a **recursive function** for calculating **e^x** using Taylor series expansion.
- The method includes **summation, power calculation, and factorial computation**.

---

### **1️⃣ Understanding the Taylor Series**

Taylor series for **e^x**:  
\[
e^x = 1 + \frac{x}{1!} + \frac{x^2}{2!} + \frac{x^3}{3!} + \frac{x^4}{4!} + ... + \frac{x^n}{n!}
\]

- More terms = **More precise approximation**.
- Three operations involved:
  1. **Summation of terms**
  2. **Power of x (x^n)**
  3. **Factorial in denominator (n!)**

---

### **2️⃣ Preparing for Recursive Implementation**

- **Observations:**

  - Previously implemented recursive functions for:  
    ✅ **Summation of N numbers**  
    ✅ **Factorial calculation**  
    ✅ **Power calculation (x^n)**
  - **Addition happens at returning time** (backtracking phase).
  - Factorial and power computations should be handled efficiently.

- **Key Challenges in Recursion:**
  - A function **can only return one value**, but we need **three** (summation, power, factorial).
  - Solution: Use **static variables** to retain values across recursive calls.

---

### **3️⃣ Recursive Approach for Taylor Series**

#### **📌 Tracing the Recursive Calls**

1. Start with `e(x, n)`, reducing `n` down to `0` (base case).
2. Each recursive call computes `P = P * x` and `F = F * n`.
3. During return phase, sum up the fractions.

#### **📌 Using Static Variables**

- **Static int P = 1** → Stores `x^n`.
- **Static int F = 1** → Stores `n!`.
- **Result accumulates as recursion unwinds**.

#### **📌 Recursive Function Breakdown**

1. **Base Case**:
   - If `n == 0`, return `1` (first term of series).
2. **Recursive Case**:
   - Call itself with `n-1`.
   - Update `P` (multiply by `x` to increase power).
   - Update `F` (multiply by `n` to compute factorial).
   - Return **previous result + (P/F)**.

---

### **4️⃣ Recursive Function Implementation**

```cpp
double e(int x, int n) {
    static double P = 1, F = 1;
    double r;

    if (n == 0) return 1; // Base case

    r = e(x, n - 1);  // Recursive call
    P = P * x;        // Update power of x
    F = F * n;        // Update factorial

    return r + (P / F);  // Return computed term sum
}
```

---

### **5️⃣ Execution and Tracing**

#### **Example Call: `e(2, 4)`**

1. **Recursive calls** reduce `n` from `4` to `0`.
2. **Returning phase**:
   - Compute `P` and `F` at each step.
   - Add each fraction to the total.

| Step | `P` (Power) | `F` (Factorial) | Computation    | Sum  |
| ---- | ----------- | --------------- | -------------- | ---- |
| 0    | 1           | 1               | 1              | 1    |
| 1    | 2           | 1               | 1 + (2/1)      | 3    |
| 2    | 4           | 2               | 3 + (4/2)      | 5    |
| 3    | 8           | 6               | 5 + (8/6)      | 6.33 |
| 4    | 16          | 24              | 6.33 + (16/24) | 7    |

---

### **6️⃣ Conclusion**

✅ **Recursive approach successfully implemented using static variables**.  
✅ **Efficiently computes e^x with minimal function calls**.  
✅ **Next: A faster approach with fewer multiplications**.
