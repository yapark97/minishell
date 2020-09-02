/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/02 13:30:42 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(char *cmd)
{
	struct stat	sb;
	char		**env_path;
	char		*new_path;
	int			i;

	i = -1;
	if (!stat(cmd, &sb))
		return (ft_strdup(cmd));
	while (g_envp[++i])
		if (!ft_strncmp(g_envp[i], "PATH=", 5))
			env_path = ft_split(g_envp[i] + 5, ':');
	i = -1;
	while (env_path[++i])
	{
		env_path[i] = ft_gnljoin(env_path[i], "/");
		new_path = ft_strjoin(env_path[i], cmd);
		if (!stat(new_path, &sb))
		{
			free_2d_arr(env_path);
			return (new_path);
		}
		free_init(&new_path, NULL);
	}
	free_2d_arr(env_path);
	return (0);
}

void	change_cmds(char **cmds)
{
	int i;

	if (!strcmp(cmds[0], "pwd"))
	{
		i = 0;
		while (cmds[++i])
			free(cmds[i]);
		cmds[1] = NULL;
	}
}

int		excutables(int fd_o, int fd_i, char **argv)
{
	pid_t	child;
	int		status;
	char	*path;

	path = find_path(argv[0]);
	child = fork();
	if (argv[0])
		change_cmds(argv);
	if (!child)
	{
		if (fd_o != 1)
			dup2(fd_o, 1);
		if (fd_i != 0)
			dup2(fd_i, 0);
		if (execve(path, argv, g_envp) == -1)
			return (0);
	}
	else
	{
		waitpid(child, &status, 0);
		g_exit_code = status / 256;
		free(path);
	}
	return (1);
}

void	do_except(char **cmds)
{
	if (g_except[SYNTAX])
	{
		ft_putstr("-minishell: syntax error near unexpected token `");
		if (g_except[SYNTAX] == '|')
			ft_putstr_newline("|'");
		else
			ft_putstr_newline("newline'");
	}
	else
	{
		print_2d_arr(cmds);
		ft_putstr_newline(": command not found");
	}
	exit(1);
}

void	exec_cmds(char ***cmds)
{
	int i;

	if (!cmds)
		return ;
	i = -1;
	while (cmds[++i])
	{
		if (redirections(cmds[i]) ||
			pipes(cmds[i]) ||
			builtins(cmds[i], cmds) ||
			excutables(1, 0, cmds[i]))
		{
		}
		else
			do_except(cmds[i]);
	}
}
