#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    void* ptr, *ptr1;
    ptr = sbrk(0);
    printf("sbrk:%p\n", ptr);
    ptr1 = malloc(100);
    ptr = sbrk(0);
    printf("sbrk:%p, ptr1:%p\n", ptr, ptr1);
    ptr1 = malloc(100);
    ptr = sbrk(0);
    printf("sbrk:%p, ptr1:%p\n",ptr, ptr1);                                                                                                                                      
    free(ptr1);
    ptr = sbrk(0);
    printf("sbrk:%p\n",ptr);
}