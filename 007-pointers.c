#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p = (int*)malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        *(p + i) = (120 * (i + 1));
    }
    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", *(p + i));
    }
    return 0;
}