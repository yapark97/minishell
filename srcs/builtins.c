#include "minishell.h"

/*static void remove_quote(char **strs)
{
	int i;
	char *temp;

	i = -1;
	while (strs[++i])
	{
		if (strs[i][ft_strlen(strs[i]) - 1] == '"')
			strs[i][ft_strlen(strs[i]) - 1] = '\0';
		if (strs[i][0] == '"')
		{
			temp = ft_strdup(strs[i] + 1);
			free(strs[i]);
			strs[i] = temp;
		}
	}
}*/

void	builtins(char **cmd)
{
	pid_t	child_pid;
	char	buf[100];

	buf[0] = 0;
	/*if (strncmp(cmd[0], "echo", 5) == 0)
		remove_quote(cmd);*/
	ft_strcat(buf, "/bin/");
	child_pid = fork();
	if (child_pid == 0)
	{
		if(execve(ft_strcat(buf, cmd[0]), cmd, 0) == -1)
			exit(1);
	}
	wait(0);
	kill(child_pid, 0);
}
