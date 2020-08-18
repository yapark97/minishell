#include "minishell.h"

static int	find_cmd_num(char **cmds)
{
	int i;

	i = 0;
	if (!cmds)
		return (i);
	while (cmds[i])
		i++;
	return (i);
}

char		***parsing_cmds(char *line, int *cmd_num)
{
	char 	**cmds;
	char	***ret;
	int		i;

	cmds = ft_split(line, ';');
	*cmd_num = find_cmd_num(cmds);
	if (*cmd_num == 0)
		return (0);
	ret = (char***)malloc(sizeof(char**) * (*cmd_num + 1));
	ret[*cmd_num] = 0;
	i = 0;
	while (i < *cmd_num)
	{
		ret[i] = ft_split(cmds[i], ' ');
		free(cmds[i]);
		i++;
	}
	free(cmds);
	return (ret);
}
