```c
#include <stdio.h>

int main()
{
int* p1;
float* p2;
double* p3;
char* p4;

    printf("%lu\n", sizeof(p1));
    printf("%lu\n", sizeof(p2));
    printf("%lu\n", sizeof(p3));
    printf("%lu\n", sizeof(p4));

    return 0;

}
```

The reason why `sizeof(p1)`, `sizeof(p2)`, `sizeof(p3)`, and `sizeof(p4)` all return `8` bytes is due to the fact that **pointers store memory addresses, and their size depends on the system architecture, not the type they point to**.

### Explanation:

1. **Pointers store addresses**: A pointer in C stores the memory address of a variable, regardless of its type.
2. **Size of a pointer depends on system architecture**:
   - On a **32-bit system**, memory addresses are 4 bytes long, so `sizeof(pointer)` would be **4**.
   - On a **64-bit system**, memory addresses are 8 bytes long, so `sizeof(pointer)` is **8**.
3. **All pointers have the same size**: Since pointers store addresses, and addresses are the same size in a given system, all pointers—whether they point to `int`, `float`, `double`, or `char`—will have the same size.

### Key Takeaway:

- The size of a pointer is determined by the system architecture, **not** the data type it points to.
- Since you are likely running this on a **64-bit system**, each pointer occupies **8 bytes**.

Let me know if you need further clarification! 😊
