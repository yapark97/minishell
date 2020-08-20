#include <signal.h>
#include <stdio.h>

sig_atomic_t sigflag = 0;

void catch_int(int a)
{
    sigflag = 1;
    printf("hello\n");
}

int main()
{
    int i = 0;
    signal(SIGINT, catch_int);
    do {
        i++;
        
        } while (1);
    
}