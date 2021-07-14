#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    void* ptr, *data1, *data2, *data3;
    void* ptr2;

    ptr = sbrk(0);
    printf("sbrk %p\n", ptr);

    data1 = malloc(100); // 单位是字节
    ptr = sbrk(0);
    printf("sbrk %p, data %p, %d\n", ptr, data1, (long)ptr - (long)data1);

    data2 = malloc(1000);
    ptr = sbrk(0);
    printf("sbrk %p, data %p, %d, %d\n", ptr, data2, (long)ptr - (long)data2, (long)data2 - (long)data1);

    data3 = malloc(100);
    ptr2 = sbrk(0);
    printf("sbrk %p, data %p, %d, %d\n", ptr2, data3, (long)ptr2 - (long)data3, (long)data3 - (long)data2);
    return 0;
}  