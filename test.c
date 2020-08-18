#include <signal.h>
#include <stdio.h>

sig_atomic_t sigflag = 0;

void catch_int(int a)
{
    sigflag = 1;
    printf("hello");
}

int main()
{
    signal(SIGINT, catch_int);
    do {
        } while (1);
    
}