### **Summary of the Transcript on the Exponentiation Function**

#### **1. Introduction to the Exponentiation Function**

The function computes exponentiation (`m^n`), meaning `m` is multiplied by itself `n` times.

For example:  
\[
2^5 = 2 \times 2 \times 2 \times 2 \times 2 = 32
\]  
The goal is to implement an efficient recursive solution for this calculation.

---

### **2. Basic Recursive Approach**

The exponentiation function follows the recurrence relation:  
\[
\text{power}(m, n) = m \times \text{power}(m, n-1)
\]  
with the base case:  
\[
\text{power}(m, 0) = 1
\]

##### **2.1 Implementation in C++**

```cpp
int power(int m, int n) {
    if (n == 0) return 1;
    return power(m, n - 1) * m;
}
```

- If `n == 0`, return `1` (base case).
- Otherwise, recursively call `power(m, n-1)`, multiplying the result by `m`.

##### **2.2 Time & Space Complexity**

- **Time Complexity:** \(O(n)\)
- **Space Complexity:** \(O(n)\) due to recursion depth.

---

### **3. Optimized Approach Using Fewer Multiplications**

To improve efficiency, we use **Exponentiation by Squaring** by reducing the number of multiplications.

#### **3.1 Key Formula for Optimization**

Instead of decreasing `n` one by one, we use the following properties:

- **If `n` is even**:  
  \[
  m^n = (m \times m)^{(n/2)}
  \]
- **If `n` is odd**:  
  \[
  m^n = m \times (m \times m)^{((n-1)/2)}
  \]

#### **3.2 Optimized Recursive Implementation in C++**

```cpp
int power(int m, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        return power(m * m, n / 2);
    } else {
        return m * power(m * m, (n - 1) / 2);
    }
}
```

- If `n` is **even**, we **square** `m` and divide `n` by 2.
- If `n` is **odd**, we extract one `m`, then apply the squaring method to `m * m`.

##### **3.3 Example Execution for `power(2,9)`**

1. `power(2,9) = 2 × power(4,4)`
2. `power(4,4) = power(16,2)`
3. `power(16,2) = power(256,1)`
4. `power(256,1) = 256 × power(65536,0)`
5. `power(65536,0) = 1` (base case)

Multiplying back:

- `power(256,1) = 256 × 1 = 256`
- `power(16,2) = 256`
- `power(4,4) = 256`
- `power(2,9) = 2 × 256 = 512`

##### **3.4 Time & Space Complexity**

- **Time Complexity:** \(O(\log n)\)
- **Space Complexity:** \(O(\log n)\) due to recursion depth.

---

### **4. Iterative Approach (Best Optimization)**

To avoid recursion overhead, we implement an **iterative version**.

#### **4.1 Iterative Function in C++**

```cpp
int power(int m, int n) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) result *= m;
        m *= m;
        n /= 2;
    }
    return result;
}
```

- Instead of recursion, we **iterate**, continuously squaring `m` and halving `n`.
- If `n` is odd, we multiply `result` by `m`.

#### **4.2 Example Execution for `power(2,9)`**

1. `n = 9`: Odd → `result *= 2`, `m = 2 × 2 = 4`, `n = 4`
2. `n = 4`: Even → `m = 4 × 4 = 16`, `n = 2`
3. `n = 2`: Even → `m = 16 × 16 = 256`, `n = 1`
4. `n = 1`: Odd → `result *= 256`, `m = 256 × 256 = 65536`, `n = 0`
5. Done. Final result = 512.

#### **4.3 Time Complexity**

- **Time Complexity:** \(O(\log n)\), as `n` is halved at each step.
- **Space Complexity:** \(O(1)\), since no recursion is used.

---

### **5. Conclusion**

| Approach                | Time Complexity | Space Complexity | Notes                      |
| ----------------------- | --------------- | ---------------- | -------------------------- |
| **Basic Recursive**     | \(O(n)\)        | \(O(n)\)         | Simple but slow            |
| **Optimized Recursive** | \(O(\log n)\)   | \(O(\log n)\)    | Uses fewer multiplications |
| **Iterative**           | \(O(\log n)\)   | \(O(1)\)         | Best approach              |

The **iterative approach** is the most efficient in terms of both time and space complexity.
