#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void test(char *temp[])
{

    temp[0] = "hello";
}

int main(int argc, char **argv, char **envp)
{
    int fd;
    const int MAX = 1000;

    fd = open("text.txt", O_WRONLY | O_CREAT | O_TRUNC);
    // fd = open("text.txt", O_RDONLY);
    // char buf[MAX];
    // read(fd, buf, MAX);
    // while (!read(fd, buf, MAX))
    //     ;
    
    char *temp[100];
    test(temp);
    printf("%s\n", temp[0]);

    pid_t child;
    int status;
    child = fork();
    char *argvs[] = {"nl", "<", "aa", 0};
    if (child == 0)
    {
        execve("/usr/bin/nl", argvs, 0);
    }
    else
    {
        waitpid(child, &status, 0);
        printf("finished\n");
    }
    printf("which first?\n");
    //close(fd);
    return (0);
}