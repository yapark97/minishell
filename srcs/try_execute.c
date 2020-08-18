#include "minishell.h"

int	try_execute(char **cmd)
{
	pid_t	child_pid;
	int		status;
	//int		es;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, 0) == -1)
			exit(1);
	}
	else
		waitpid(child_pid, &status, 0);
	
	/*if (WIFEXITED(status))
	{
		es = WEXITSTATUS(status);
		printf("status : %d es : %d\n",status, es);
	}*/
	return (status / 256);
}
