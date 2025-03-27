### **Exponent Function (m^n) - Recursive & Optimized Solutions**

#### **1. Understanding the Problem**

- The exponent function calculates ( m^n ), which means multiplying ( m ) by itself ( n ) times.
- Example: ( 2^5 = 2 × 2 × 2 × 2 × 2 ).
- Mathematically: ( Power(m, n) = m × m × m × ... × m ) (total ( n ) times).

#### **2. Recursive Approach**

- The recursive definition follows:
  - ( Power(m, n) = Power(m, n-1) × m ) when ( n > 0 ).
  - Base case: ( Power(m, 0) = 1 ) since any number raised to 0 is 1.

##### **2.1 Implementing the Recursive Function**

```cpp
int power(int m, int n) {
    if (n == 0) return 1;
    return power(m, n - 1) * m;
}
```

- This function calls itself ( n ) times, leading to **O(n) time complexity**.
- It also consumes **O(n) space** due to recursive calls being stored in the stack.

##### **2.2 Execution & Trace for power(2,9)**

- Step-by-step breakdown:
  - ( Power(2, 9) = Power(2, 8) × 2 )
  - ( Power(2, 8) = Power(2, 7) × 2 )
  - ...
  - ( Power(2, 1) = Power(2, 0) × 2 )
  - ( Power(2, 0) = 1 ) (Base case)
- The function makes **n+1 recursive calls** (10 calls for ( n = 9 )).
- Total **9 multiplications performed**.

#### **3. Optimized Approach: Reducing Multiplications**

- Instead of decrementing ( n ) one by one, we can **halve** the exponent when possible:
  - If ( n ) is even: ( m^n = (m^{n/2})^2 )
  - If ( n ) is odd: ( m^n = m × (m^{(n-1)/2})^2 )

##### **3.1 Optimized Recursive Function**

```cpp
int power(int m, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int half = power(m, n / 2);
        return half * half;
    } else {
        return m * power(m, (n - 1) / 2) * power(m, (n - 1) / 2);
    }
}
```

- **Time Complexity: O(log n)** since the exponent is reduced by half each time.
- **Space Complexity: O(log n)** due to recursive calls.

##### **3.2 Execution & Trace for power(2,9)**

- Step-by-step breakdown:
  - ( Power(2,9) = 2 × Power(2,4) × Power(2,4) )
  - ( Power(2,4) = Power(2,2) × Power(2,2) )
  - ( Power(2,2) = Power(2,1) × Power(2,1) )
  - ( Power(2,1) = 2 × Power(2,0) )
  - ( Power(2,0) = 1 )
- Reduces multiplications from **9 to 6**.

#### **4. Further Optimization**

- The above function makes redundant recursive calls. We can optimize further:

```cpp
int power(int m, int n) {
    if (n == 0) return 1;
    int halfPower = power(m, n / 2);
    if (n % 2 == 0) return halfPower * halfPower;
    else return m * halfPower * halfPower;
}
```

- This eliminates duplicate calls, keeping time complexity **O(log n)**.

#### **5. Iterative Approach (Student Exercise)**

- The power function can also be implemented iteratively using loops.
- It avoids recursion and reduces memory consumption.

---

### **Key Takeaways**

1. **Basic Recursive Method:** ( O(n) ) time, ( O(n) ) space.
2. **Optimized Recursive Method (Halving Exponent):** ( O(log n) ) time, ( O(log n) ) space.
3. **Further Optimized Recursive Method:** Eliminates duplicate calls, still ( O(log n) ).
4. **Iterative Method:** Achieves the same result without recursion.
