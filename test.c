#include <stdio.h>
#include "srcs/minishell.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    pipe(fd);
    pid_t child;
    int status;
    child = fork();
    char *line;

    char *argvs[] = {"ls", 0};
    char *argvs2[] = {"grep", ".c", 0};
    if (child == 0)
    {
        close(fd[0]);
        dup2(fd[1], 1);
        execve("/bin/ls", argvs, envp);
    }
    else
    {
        close(fd[1]);
        waitpid(child, &status, 0);
        dup2(fd[0], 0);
        execve("/bin/grep", argvs2, envp);
    }
    return 0;
}