### **Indirect Recursion in C++**

📌 **Indirect Recursion Explanation**

```
├── Uses multiple functions calling each other in a cycle.
├── Function A calls Function B, and Function B calls Function A.
├── The recursion continues until a base condition is met.
```

📌 **Implementation of Indirect Recursion**

```
├── **Function A**
│ ├── Takes parameter `n`
│ ├── If `n > 0`, prints `n`
│ ├── Calls Function B with `n - 1`
│
├── **Function B**
│ ├── Takes parameter `n`
│ ├── If `n > 1`, prints `n`
│ ├── Calls Function A with `n / 2`
```

📌 **Handling Compilation Error**

```
├── Encountered error: **Function B is not defined before usage in Function A**
├── **Solution:** Declare Function B **before** Function A to resolve the error.
```

📌 **Code Implementation**

```cpp
#include <iostream>
using namespace std;

// Function Prototype
void B(int n);

void A(int n) {
    if (n > 0) {
        cout << n << " ";
        B(n - 1);
    }
}

void B(int n) {
    if (n > 1) {
        cout << n << " ";
        A(n / 2);
    }
}

int main() {
    A(20);  // Calling Function A with n = 20
    return 0;
}
```

📌 **Program Execution and Output**

```
├── Initial Call: `A(20)`
├── Execution Flow:
│ ├── `A(20)` → Prints `20` → Calls `B(19)`
│ ├── `B(19)` → Prints `19` → Calls `A(9)`
│ ├── `A(9)` → Prints `9` → Calls `B(8)`
│ ├── `B(8)` → Prints `8` → Calls `A(4)`
│ ├── `A(4)` → Prints `4` → Calls `B(3)`
│ ├── `B(3)` → Prints `3` → Calls `A(1)`
│ ├── `A(1)` → Prints `1` → Calls `B(0)` (Stops)
├── Final Output: **20 19 9 8 4 3 1**
```

📌 **Key Takeaways**

```
├── Indirect recursion involves two or more functions calling each other.
├── Function prototypes are necessary to avoid compilation errors.
├── Recursion stops when the base condition is met.
├── Indirect recursion can be traced using debugging tools.
```

✅ **Conclusion**
The program successfully demonstrates indirect recursion by alternating calls between Function A and Function B until the recursion terminates.
