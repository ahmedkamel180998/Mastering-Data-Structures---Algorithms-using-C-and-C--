### **Mind Map: Recursive Implementation of Taylor Series Using Horner’s Rule**

#### **📌 Main Topic: Recursive Function for e^x (Taylor Series)**

➡ **Horner’s Rule Approach**

- Used to optimize Taylor series evaluation.
- Reduces multiplications and improves efficiency.

---

### **1️⃣ Function Implementation**

#### **📌 Function Definition**

- **Static Variable**: `double s` (stores the sum).
- **Base Case**: If `n == 0`, return `s`.
- **Recursive Case**:
  - Update `s` using:  
    \[
    s = 1 + \frac{x}{n} \times s
    \]
  - Make recursive call: `return e(x, n - 1)`.

---

### **2️⃣ Key Considerations**

✅ **Integer Division Issue**

- Since `x` and `n` are integers, division will result in an integer.
- **Solution**:
  - **Typecast `x/n` to double**.
  - OR **Multiply `x` with `s` before division**.

✅ **Precision Handling**

- More terms (**higher `n` value**) increase precision.
- Example:
  - `e(1,10) → 2.718282`
  - `e(2,10) → 7.38871`

---

### **3️⃣ Program Execution**

#### **📌 Running the Function**

- **Print result** using `printf("%.6lf\n", e(1,10));`.
- **Validation**: Checked results against a calculator.
- **Observation**: Increasing terms improves accuracy.

---

### **4️⃣ Final Takeaway**

✅ Horner’s Rule **optimizes Taylor series calculations**.  
✅ Recursive function **performs multiplications at calling time**.  
✅ Increasing terms **improves precision**.
