#include "minishell.h"

void	builtins(char **cmd)
{
	pid_t	child_pid;
	char	buf[100];

	buf[0] = 0;
	if (strncmp(cmd[0], "env", 4) == 0)
	{
		write(1, "env\n", 4);
		ft_strcat(buf, "/usr/bin/");
	}
	else
		ft_strcat(buf, "/bin/");
	child_pid = fork();
	if (child_pid == 0)
	{
		if(execve(ft_strcat(buf, cmd[0]), cmd, 0) == -1)
			exit(1);
		
	}
	char *temp;
	temp = ft_strcat(buf, cmd[0]);
	write(1, temp, ft_strlen(temp));
	write(1, "\n", 1);
	wait(0);
	kill(child_pid, 0);
}
