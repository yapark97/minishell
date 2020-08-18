#include "minishell.h"

int	try_execute(char **cmd)
{
	pid_t	child_pid;
	
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, 0) == -1)
			exit(1);
	}
	else
		wait(&child_pid);
	return (0);
}
