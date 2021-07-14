#include <stdlib.h>
#include <stdio.h>

int bssvar, bssvar2, bssvar3, bssvar4, bssvar5, bssvar6;
int dsvar = 1, dsvar2 = 1, dsvar3 = 1, dsvar4 = 1, dsvar5 = 1;
char c = 'c';

int main(int argc, char const *argv[])
{
    // 进程的内存布局 - bss segment & data segment
    printf("bssvar: %p, %x, %X, %#x, %#X\n", &bssvar, &bssvar2, &bssvar3, &bssvar4, &bssvar5);
    printf("ds var: %p, %x, %X, %#x, %#X, %p\n", &dsvar, &dsvar2, &dsvar3, &dsvar4, &dsvar5, &c);
    printf("bssvar begin at: %p, dsvar begin at: %p, gap: %d\n", &bssvar, &dsvar, ((long)&bssvar - (long)&dsvar));
    
    
    return 0;
}

