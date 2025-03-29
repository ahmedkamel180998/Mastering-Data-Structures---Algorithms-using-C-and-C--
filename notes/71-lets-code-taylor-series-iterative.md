### **Mind Map: Iterative Implementation of Taylor Series**

#### **📌 Main Topic: Implementing e^x Using Iterative Method**

➡ **Uses a loop instead of recursion**  
➡ **Optimized for efficiency and precision**

---

### **1️⃣ Function Implementation**

#### **📌 Variable Declarations**

- **s** → Stores the result, initialized to `1`.
- **i** → Loop variable, starts from `1`.
- **numerator** → `double`, initialized to `1`.
- **denominator** → `double`, initialized to `1`.

---

### **2️⃣ Iterative Approach (For Loop)**

✅ **Loop starts from `i = 1` to `n`**  
✅ **Update values in each iteration**:

- `numerator *= x` → Multiplies by `x` each time.
- `denominator *= i` → Calculates factorial.
- `s += numerator / denominator` → Adds the term to the sum.  
  ✅ **After loop ends, return `s`**.

---

### **3️⃣ Function Execution**

#### **📌 Running the Function**

- **Print result** using `printf("%lf\n", e(1,10));`.
- **Expected Output**: Matches previous results (`2.718282`).

✅ **Correctly computes e^x for n terms**  
✅ **More terms = Higher precision**

---

### **4️⃣ Final Takeaway**

✅ Iterative method **avoids recursion overhead**.  
✅ Uses **factorial and power calculations within loop**.  
✅ **Efficient and precise** for Taylor series evaluation.
