### **Summary: Indirect Recursion in C++**

#### **1. Introduction to Indirect Recursion**

- Indirect recursion occurs when multiple functions call one another in a circular manner.
- Example:
  - Function `A` calls Function `B`
  - Function `B` calls Function `C`
  - Function `C` calls Function `A`
- This creates a cycle of recursive calls.
- Instead of a function calling itself directly, it calls another function, which in turn calls the original function.

#### **2. Skeleton of Indirect Recursion**

- **Function A:** Contains a condition and calls Function B if the condition is met.
- **Function B:** Contains a condition and calls Function A if the condition is met.
- Both functions call each other with a reduced value of `n`.
- The recursion stops when a base condition is met in either function.

#### **3. Example of Indirect Recursion**

##### **C++ Code Implementation**

```cpp
#include <iostream>
using namespace std;

// Function A definition
void A(int n);

// Function B definition
void B(int n) {
    if (n > 1) {
        cout << n << " ";
        A(n / 2);  // Function A is called with half the value of n
    }
}

// Function A definition
void A(int n) {
    if (n > 0) {
        cout << n << " ";
        B(n - 1);  // Function B is called with n-1
    }
}

int main() {
    A(20);  // Initial call to function A with value 20
    return 0;
}
```

#### **4. Step-by-Step Execution Trace**

1. **Initial Call:** `A(20)`

   - Prints `20`
   - Calls `B(19)`

2. **Function B Execution:** `B(19)`

   - Prints `19`
   - Calls `A(9)` (`19 / 2 = 9`)

3. **Function A Execution:** `A(9)`

   - Prints `9`
   - Calls `B(8)` (`9 - 1 = 8`)

4. **Function B Execution:** `B(8)`

   - Prints `8`
   - Calls `A(4)` (`8 / 2 = 4`)

5. **Function A Execution:** `A(4)`

   - Prints `4`
   - Calls `B(3)` (`4 - 1 = 3`)

6. **Function B Execution:** `B(3)`

   - Prints `3`
   - Calls `A(1)` (`3 / 2 = 1`)

7. **Function A Execution:** `A(1)`

   - Prints `1`
   - Calls `B(0)` (`1 - 1 = 0`)

8. **Function B Execution:** `B(0)`
   - Since `n` is not greater than `1`, the function terminates.

#### **5. Recursion Unwinding (Backtracking)**

- Once `B(0)` terminates, control returns to previous calls in reverse order:
  - `A(1) → B(3) → A(4) → B(8) → A(9) → B(19) → A(20)`
- The recursion cycle completes, and the program ends.

#### **6. Output of the Program**

```
20 19 9 8 4 3 1
```

#### **7. Conclusion**

- Indirect recursion involves multiple functions calling each other in a cyclic manner.
- The recursion stops when a base condition is met.
- This technique is useful for scenarios where function execution depends on intermediate operations.
- The execution follows a call-return sequence, maintaining a stack of recursive calls until the base condition is reached.
