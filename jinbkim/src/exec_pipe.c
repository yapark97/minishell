/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/01 19:19:41 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**allocate_path(char **cmd1, char **cmd2)
{
	char **path;

	path = (char **)malloc(sizeof(char *) * 3);
	path[0] = find_path(cmd1[0]);
	path[1] = find_path(cmd2[0]);
	path[2] = NULL;
	if (!path[0] || !path[1])
	{
		if (!path[1])
		{
			free(path[0]);
			ft_putstr(*cmd2);
			ft_putstr_newline(": command not found");
		}
		if (!path[0])
		{
			free(path[1]);
			ft_putstr(*cmd1);
			ft_putstr_newline(": command not found");
		}
		free(path);
		return (0);
	}
	return (path);
}

void	connect_pipe(int *fd, char **path, char **cmd1, char **cmd2)
{
	pid_t	child;
	int		status;

	pipe(fd);
	child = fork();
	if (!child)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(path[0], cmd1, g_envp);
	}
	else
	{
		close(fd[1]);
		waitpid(child, &status, 0);
		dup2(fd[0], 0);
		execve(path[1], cmd2, g_envp);
	}
}

void	pipes_exec(char **cmd1, char **cmd2)
{
	pid_t	child;
	char	**path;
	int		fd[2];
	int		status;

	if (!(path = allocate_path(cmd1, cmd2)))
		return ;
	child = fork();
	if (!child)
		connect_pipe(fd, path, cmd1, cmd2);
	else
	{
		waitpid(child, &status, 0);
		g_exit_code = status / 256;
		free_2d_arr(path);
	}
}

int		pipes(char **cmd)
{
	char	**cmd1;
	char	**cmd2;
	int		i;

	i = -1;
	cmd1 = 0;
	cmd2 = 0;
	while (cmd[++i])
	{
		if (!ft_strcmp(cmd[i], "|"))
		{
			cmd1 = copy_2d_arr(cmd, i);
			cmd2 = copy_2d_arr(&cmd[i + 1], AUTO_SIZE);
			pipes_exec(cmd1, cmd2);
			free_2d_arr(cmd1);
			free_2d_arr(cmd2);
			return (1);
		}
	}
	return (0);
}
