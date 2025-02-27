#include <stdio.h>
#include <stdlib.h>

struct rectangle{
    int length;
    int breadth;
};

int main()
{
    struct rectangle* p;
    p = (struct rectangle*)malloc(sizeof(struct rectangle));
    p->length = 10;
    p->breadth = 5;
    printf("%d\n", p->length * p->breadth);
    free(p);
    p = NULL;
    printf("Pointer after free and assigned with NULL: %p\n", (void*)p);
    return 0;
}