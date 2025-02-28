### **Detailed Summary of the Transcript on Recursion and Stack Usage**

The transcript explains how recursion utilizes the stack memory by analyzing two recursive functions (`fun1()` and `fun2()`). It provides a step-by-step breakdown of how activation records are created and deleted, showing how memory is used during recursion.

---

## **Memory Model in Recursion**

The memory in a program is divided into three sections:

1. **Code Section** – Stores the machine code of the functions.
2. **Stack Section** – Used for function calls and activation records.
3. **Heap Section** – Used for dynamic memory allocation.

The program consists of two functions: `main()` and `fun1()`. The machine code of these functions is already stored in the code section before execution begins.

---

## **Execution of `main()` and Stack Usage**

1. The program execution starts from the `main()` function.
2. In `main()`, the first statement creates a variable `x` with a value of `3`.
   - An **activation record** for `main()` is created in the stack, containing `x = 3`.
3. The next statement calls `fun1(x)`, passing `x` as an argument.
   - A new **activation record** for `fun1(3)` is created with `n = 3`.

---

## **Recursive Execution of `fun1()`**

### **Step-by-Step Function Calls:**

1. **First Call:** `fun1(3)`

   - Checks `if (n > 0)`, which is true.
   - Prints `3` and calls `fun1(2)`.
   - A new **activation record** is created for `fun1(2)` with `n = 2`.

2. **Second Call:** `fun1(2)`

   - Checks `if (n > 0)`, which is true.
   - Prints `2` and calls `fun1(1)`.
   - A new **activation record** is created for `fun1(1)` with `n = 1`.

3. **Third Call:** `fun1(1)`

   - Checks `if (n > 0)`, which is true.
   - Prints `1` and calls `fun1(0)`.
   - A new **activation record** is created for `fun1(0)` with `n = 0`.

4. **Fourth Call:** `fun1(0)`
   - Checks `if (n > 0)`, which is false.
   - Does not enter the conditional statement and returns.
   - The **activation record for `fun1(0)` is deleted** from the stack.

---

## **Returning and Deleting Activation Records**

Once `fun1(0)` finishes, the function starts returning:

1. `fun1(0)` returns to `fun1(1)`, and the **activation record of `fun1(0)` is deleted**.
2. `fun1(1)` has no further statements, so it returns, and **its activation record is deleted**.
3. `fun1(2)` has no further statements, so it returns, and **its activation record is deleted**.
4. `fun1(3)` has no further statements, so it returns, and **its activation record is deleted**.
5. Finally, `main()` finishes execution, and **its activation record is deleted**.

---

## **Stack Size and Space Complexity**

1. **Size of the Stack:**

   - The total number of activation records (excluding `main`) is **4**.
   - The stack size depends on the number of recursive calls.
   - Each activation record contains only one variable `n`.

2. **Memory Consumption:**
   - If an integer variable takes **2 or 4 bytes**, the memory consumption is **O(n)**.
   - The number of activation records is **n + 1**, but in Big-O notation, we consider only the dominant term, so we write **O(n)**.

---

## **Execution of `fun2()` and Comparison with `fun1()`**

Another function `fun2()` is analyzed, which differs from `fun1()` in the order of printing and calling:

- `fun1()` **prints first and then calls itself**.
- `fun2()` **calls itself first and then prints**.

### **Step-by-Step Execution of `fun2()`**

1. Starts from `main()`, creating an activation record with `x = 3`.
2. Calls `fun2(3)`, creating an activation record for `fun2(3)`.
3. **Recursive Calls:**
   - Calls `fun2(2)`, creating an activation record.
   - Calls `fun2(1)`, creating an activation record.
   - Calls `fun2(0)`, creating an activation record.
   - `fun2(0)` does not satisfy `if (n > 0)`, so it returns.
4. **Returning and Printing:**
   - `fun2(1)` prints `1`, then returns and its activation record is deleted.
   - `fun2(2)` prints `2`, then returns and its activation record is deleted.
   - `fun2(3)` prints `3`, then returns and its activation record is deleted.

### **Key Difference Between `fun1()` and `fun2()`**

- `fun1()` prints **before calling the function** (top-down approach).
- `fun2()` prints **after returning from the function** (bottom-up approach).

---

## **Space Complexity of Recursive Functions**

- The number of calls made is **n + 1**.
- The number of activation records created is also **n + 1**.
- The space complexity is **O(n)**, as the stack stores `n + 1` activation records.

---

## **Next Topic: Time Complexity of Recursive Functions**

The transcript concludes by introducing the next topic: **how to determine the time complexity of recursive functions**. The explanation will be continued with an example to analyze the execution time of a recursive function.

---

### **Final Key Takeaways**

- **Recursion uses the stack to store function calls as activation records.**
- **Each recursive call creates a new activation record that stores local variables.**
- **When the base case is met, function calls start returning, and activation records are deleted.**
- **Both `fun1()` and `fun2()` have the same space complexity of O(n), but they differ in execution order.**
- **Recursive functions consume extra memory due to stack usage.**
