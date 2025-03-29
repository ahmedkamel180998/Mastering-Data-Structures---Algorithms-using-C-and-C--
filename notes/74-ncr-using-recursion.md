# **Combination Formula and Its Implementation**

## **1. Introduction to Combination Formula**

- The combination formula, also known as the selection formula, is used to determine how many ways we can select a subset from a given set of objects.
- Unlike permutations, where the order of selection matters, in combinations, the order does not matter.

**Example:**  
Given a set of alphabets `{A, B, C, D, E, F, G}`, if we need to select 3 letters, we can have selections like:

- `{A, B, C}`, `{A, B, D}`, `{A, C, D}`, etc.

However, `{A, B, C}` is the same as `{C, A, B}` since order does not change the selection.

- The mathematical notation for combination is **N C R** or **C(n, r)**.

---

## **2. Combination Formula Explanation**

The formula for computing combinations is:

```math
C(n, r) = \frac{n!}{r! \times (n - r)!}
```

where **n! (n factorial)** is the product of all integers from 1 to n.

### **Rules of Combination Formula:**

1. **N (total number of objects) must be greater than or equal to R (number of objects selected).**

   - If `N = 5`, then `R` can take values from `0 to 5`.
   - `C(5,0)`, `C(5,1)`, `C(5,2)`, `C(5,3)`, `C(5,4)`, `C(5,5)`.
   - `R` cannot be greater than `N`.

2. **Special Cases:**
   - `C(n, 0) = 1` (Choosing nothing from n elements has only one way: choosing nothing).
   - `C(n, n) = 1` (Choosing all elements from n elements has only one way).

---

## **3. Iterative Function to Calculate Combination (NCR)**

To compute `C(n, r)`, we can use the factorial formula and compute it using an iterative approach.

### **Steps to Compute `C(n, r)` Iteratively:**

1. Calculate `n!`, `r!`, and `(n-r)!` separately.
2. Divide `n!` by `r! × (n-r)!`
3. Return the result.

**Code for Iterative Approach:**

```cpp
#include <iostream>
using namespace std;

// Function to calculate factorial iteratively
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate nCr using factorial
int combination(int n, int r) {
    if (r > n) return 0; // Invalid case
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n = 5, r = 2;
    cout << "C(" << n << ", " << r << ") = " << combination(n, r) << endl;
    return 0;
}
```

**Time Complexity:**

- Computing `factorial(n)` takes **O(n)** time.
- Since we calculate three factorials separately, the overall complexity is **O(n)**.

---

## **4. Recursive Approach Using Pascal’s Triangle**

Instead of computing factorials explicitly, we can use Pascal’s Triangle.

### **Understanding Pascal’s Triangle:**

Each entry in Pascal’s Triangle follows this rule:

\[
C(n, r) = C(n-1, r-1) + C(n-1, r)
\]

where:

- `C(n-1, r-1)` represents the number of ways to choose `r-1` elements from `n-1` elements.
- `C(n-1, r)` represents the number of ways to choose `r` elements from `n-1` elements.

**Example of Pascal’s Triangle for `n=4`**

```
         1
       1   1
     1   2   1
   1   3   3   1
 1   4   6   4   1
```

From this,

- `C(4,2) = C(3,1) + C(3,2)`
- `C(3,1) = C(2,0) + C(2,1)`
- `C(3,2) = C(2,1) + C(2,2)`
- Base cases: `C(n, 0) = 1` and `C(n, n) = 1`.

---

## **5. Recursive Function for Combination (NCR) Using Pascal’s Triangle**

Instead of computing factorials, we break the problem into subproblems using recursion.

**Recursive Approach Code:**

```cpp
#include <iostream>
using namespace std;

// Recursive function to calculate nCr using Pascal’s Triangle
int combination_recursive(int n, int r) {
    if (r == 0 || r == n)
        return 1; // Base case: C(n, 0) = C(n, n) = 1
    return combination_recursive(n - 1, r - 1) + combination_recursive(n - 1, r);
}

int main() {
    int n = 5, r = 2;
    cout << "C(" << n << ", " << r << ") = " << combination_recursive(n, r) << endl;
    return 0;
}
```

### **Time Complexity Analysis**

- The recursion tree grows exponentially.
- For `C(n, r)`, we make `2` recursive calls per function call.
- Worst-case time complexity: **O(2^n)**.

---

## **6. Optimized Approach Using Memoization**

To reduce redundant calculations, we use **Memoization**.

- Store already computed values in a 2D array.
- Before making a recursive call, check if the value is already stored.
- If it is, return the stored value instead of recomputing.

**Code for Memoized Recursive Combination Function:**

```cpp
#include <iostream>
using namespace std;

const int MAX = 100;
int memo[MAX][MAX]; // Memoization table

// Function with Memoization
int combination_memo(int n, int r) {
    if (r == 0 || r == n)
        return 1;

    if (memo[n][r] != -1) // If value is already computed, return it
        return memo[n][r];

    return memo[n][r] = combination_memo(n - 1, r - 1) + combination_memo(n - 1, r);
}

int main() {
    int n = 5, r = 2;

    // Initialize memoization table with -1
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            memo[i][j] = -1;

    cout << "C(" << n << ", " << r << ") = " << combination_memo(n, r) << endl;
    return 0;
}
```

### **Time Complexity:**

- Using memoization, each `C(n, r)` is computed **only once**.
- Instead of exponential time `O(2^n)`, we reduce it to **O(n^2)**.

---

## **7. Conclusion**

- **Iterative Method:** Uses factorials and is simple but inefficient for large `n`.
- **Recursive Method:** Uses Pascal’s Triangle but has exponential complexity.
- **Memoized Recursive Method:** Optimized version reducing redundant calculations to **O(n^2)**.
