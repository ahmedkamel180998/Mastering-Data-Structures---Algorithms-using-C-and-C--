### **Summary of the Transcript on the Exponentiation Function**

#### **1. Introduction to the Exponentiation Function**

The function computes exponentiation (`m^n`), meaning `m` is multiplied by itself `n` times.

For example:  
[
2^5 = 2 × 2 × 2 × 2 × 2 = 32
]  
The goal is to implement an efficient recursive solution for this calculation.

---

### **2. Basic Recursive Approach**

The exponentiation function follows the recurrence relation:  
[
Power(m, n) = m × Power(m, n-1)
]  
with the base case:  
[
Power(m, 0) = 1
]

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

```
  - If ( n ) is even:  m^n = (    (m × m) ^   (n/2)       )
  - If ( n ) is odd :  m^n = (m × (m × m) ^ ( (n-1)/2 )   )
```

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

### **5. Conclusion**

| Approach                | Time Complexity | Space Complexity | Notes                      |
| ----------------------- | --------------- | ---------------- | -------------------------- |
| **Basic Recursive**     | \(O(n)\)        | \(O(n)\)         | Simple but slow            |
| **Optimized Recursive** | \(O(log n)\)    | \(O(log n)\)     | Uses fewer multiplications |
