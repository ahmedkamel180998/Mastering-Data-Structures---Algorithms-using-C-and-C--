### **🧠 Mind Map: Power Function Implementation**

#### **1️⃣ Introduction**

- Implementing **Power Function** (`m^n`)
- Two versions:
  - **Basic recursive approach**
  - **Optimized recursive approach (fewer multiplications)**

#### **2️⃣ Basic Recursive Approach**

- Function: `power(m, n)`
- **Base Case:** If `n == 0`, return `1`
- **Recursive Case:** Return `m * power(m, n - 1)`
- **Example Execution:**
  - `power(2, 9) → 512`
  - `power(3, 4) → 81`
- ✅ **Working correctly**

#### **3️⃣ Optimized Recursive Approach (Exponentiation by Squaring)**

- Function: `power1(m, n)`
- **Base Case:** If `n == 0`, return `1`
- **Even `n`:**
  - `m^n = (m × m)^(n/2)`
- **Odd `n`:**
  - `m^n = m × (m × m)^((n-1)/2)`
- **Example Execution:**
  - `power1(2, 9) → 512`
  - `power1(2, 8) → 256`
  - `power1(9, 3) → 729`
- ✅ **Efficient with fewer multiplications**

#### **4️⃣ Conclusion**

- **Two approaches:**
  1.  **Basic recursive** (more multiplications)
  2.  **Optimized recursive** (faster, uses squaring method)
- ✅ **Both versions tested and working correctly**
- ✍️ **Encouraged to practice implementing the functions**
