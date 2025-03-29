### **Taylor Series Recursive Function (e^x)**

📌 **Concept Explanation**

- Taylor series is used to approximate **e^x**.
- More terms → More precision.
- Uses three operations: **Summation, Power, and Factorial**.
- Function must handle multiple calculations but return a single value.

📌 **Recursive Function Implementation**

#### **1️⃣ Function Definition**

- **Name:** `e(x, n)`
- **Return Type:** `double` (to handle decimal values).
- **Parameters:** `x` (exponent), `n` (number of terms).

#### **2️⃣ Static Variables**

- **p (power)** → initialized as `1`.
- **f (factorial)** → initialized as `1`.
- **r (result storage)** → used to store intermediate results.

#### **3️⃣ Base Case**

- If `n == 0`, return `1`.

#### **4️⃣ Recursive Call**

- `r = e(x, n-1)` → Compute for smaller terms first.
- Update power: `p = p * x`.
- Update factorial: `f = f * n`.
- Return `r + (p / f)`.

📌 **Function Execution & Testing**

#### **1️⃣ Function Call Example**

- `e(1, 10)` → Computes **e^1** using **10 terms**.
- Output: `2.718282` (compared with calculator).

#### **2️⃣ Precision Adjustment**

- More terms (`n`) = More accurate results.
- Example calculations for `e^3` and `e^4`.
- Increased terms to **15** for better precision.

📌 **Key Takeaways**  
✅ Uses **recursion** and **static variables**.  
✅ Can approximate `e^x` for any given `x`.  
✅ More terms = Higher accuracy.  
✅ Faster than traditional factorial-based computation.
