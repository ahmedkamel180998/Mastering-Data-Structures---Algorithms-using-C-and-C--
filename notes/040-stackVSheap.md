### **Summary of the Video on Static and Dynamic Memory Allocation**

#### **Introduction**

The video focuses on **Static and Dynamic Memory Allocation**, covering the following key topics:

- Understanding memory and how it is utilized.
- How a program uses **main memory**.
- Difference between **static and dynamic memory allocation**.

#### **Understanding Memory**

- **Memory Structure:**
  - Memory consists of small **addressable units** called **bytes**.
  - Each **byte has a unique address**, which is a single-dimensional value (not like an (x, y) coordinate system).
  - Example: Memory addresses may start from **0, 1, 2, 3…** up to the total memory size.
- **Memory Size Example:**

  - Consider a memory segment of **64 KB (kilobytes)**.
  - The first address is **0**, and the last address is **65535**.
  - Total bytes = **65536** (**64 × 1024**).

- **Modern Memory Usage:**
  - Modern computers have larger RAM sizes (e.g., **4 GB, 8 GB**).
  - However, **memory is divided into smaller manageable sections called segments**, usually **64 KB each**.

#### **How a Program Uses Main Memory**

- **Memory Segmentation:**

  - Main memory is divided into three sections for a program:
    1. **Code Section** – Stores the program's machine code.
    2. **Stack** – Stores function variables.
    3. **Heap** – Used for dynamically allocated memory.

- **Program Execution Process:**
  - A program stored on the **hard disk** is first **loaded into the code section** of the main memory.
  - The **CPU executes** the program, utilizing stack and heap memory.

#### **Understanding Stack and Heap**

- **Stack Memory:**

  - The **stack stores local variables** inside functions.
  - Example:

    ```cpp
    int a;   // Integer variable
    float b; // Float variable
    ```

    - **Assumption:** Integer takes **2 bytes**, and float takes **4 bytes**.
    - **Total memory allocated:** **6 bytes** inside the **stack**.

  - The memory allocated for a function inside the stack is called:

    - **Stack Frame** or **Activation Record**.

  - **Stack memory allocation happens at compile time** (before execution).
  - Since the memory size is **fixed at compile time**, this is called **Static Memory Allocation**.

#### **Static Memory Allocation**

- **Definition:** Memory allocation that is determined **at compile time**.
- **Example:** Local variables in a function (inside stack memory).
- **Characteristics:**
  - The **compiler determines** the required memory **before execution**.
  - The **size of memory is fixed** and cannot change at runtime.
  - This type of memory allocation is **efficient but inflexible**.

#### **Conclusion**

- The video provides an overview of how memory is structured and utilized in a program.
- **Static memory allocation** is discussed in detail, explaining how the stack memory works and how variables are allocated inside it.
- **Next Steps:** The video will likely cover **dynamic memory allocation** (heap memory) in the following sections.
