/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/01 19:43:53 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_in(char **cmd, const char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("-minishell: ");
		ft_putstr(file);
		ft_putstr_newline(": No such file or directory");
		return ;
	}
	excutables(1, fd, cmd);
	close(fd);
}

void	redir_out(char **cmd, const char *file, char overwrite)
{
	int fd;

	if (overwrite == 'y')
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else
		fd = open(file, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
	excutables(fd, 0, cmd);
	close(fd);
}

int		redirections(char **cmd)
{
	char	**cmd_cpy;
	int		i;

	i = -1;
	cmd_cpy = 0;
	while (cmd[++i])
	{
		if (!ft_strcmp(cmd[i], "<") || !ft_strcmp(cmd[i], ">")
			|| !ft_strcmp(cmd[i], ">>"))
			cmd_cpy = copy_2d_arr(cmd, i);
		if (!ft_strcmp(cmd[i], "<"))
			redir_in(cmd_cpy, cmd[i + 1]);
		else if (!ft_strcmp(cmd[i], ">"))
			redir_out(cmd_cpy, cmd[i + 1], 'y');
		else if (!ft_strcmp(cmd[i], ">>"))
			redir_out(cmd_cpy, cmd[i + 1], 'n');
		if (cmd_cpy)
		{
			free_2d_arr(cmd_cpy);
			return (1);
		}
	}
	return (0);
}
