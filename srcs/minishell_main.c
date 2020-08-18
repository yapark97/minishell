/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:12:06 by yapark            #+#    #+#             */
/*   Updated: 2020/08/18 16:00:52 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>

sig_atomic_t sigflag = 0;

static void catch_int(int sig_num)
{
	sigflag = 1;
	printf("sig_num : %d\n", sig_num);
}

static void	free_cmds(char ***cmds)
{
	int	i;
	int j;

	if (!cmds)
		return ;
	i = -1;
	while (cmds[++i])
	{
		j = -1;
		while (cmds[i][++j])
		{
			if (cmds[i][j])
				free(cmds[i][j]);
		}
		free(cmds[i]);
	}
	free(cmds);
}

static void	exit_minishell(char ***cmds)
{
	write(1, "exit\n", 5);
	free_cmds(cmds);
	exit(99);
}

static void	read_cmds(char ***cmds, int cmd_num)
{
	int	i;

	i = -1;
	while (++i < cmd_num)
	{
		if (ft_strncmp(cmds[i][0], "cd", 3) == 0)
			do_cd(cmds[i][1]);
		else if (ft_strncmp(cmds[i][0], "ls", 3) == 0 ||
				ft_strncmp(cmds[i][0], "pwd", 4) == 0 ||
				ft_strncmp(cmds[i][0], "echo", 5) == 0 ||
				ft_strncmp(cmds[i][0], "env", 4) == 0)
			builtins(cmds[i]);
		else if (ft_strncmp(cmds[i][0], "exit", 5) == 0)
			exit_minishell(cmds);
		else if (ft_strncmp(cmds[i][0], "pid", 4) == 0)
			printf("current pid : %d\n", getpid());
		else
			try_execute(cmds[i]);
	}
}

int			main(void)
{
	char	*line;
	char	***cmds;
	int		cmd_num;

	//exit(1);
	line = 0;
	while (1)
	{
		write(1, "minishell$ ", 11);
		signal(SIGINT, catch_int);

		//printf("signal return value : %d\n", ret);
		if (get_next_line(0, &line) < 0)
			break ;

		if (line)
		{
			cmds = parsing_cmds(line, &cmd_num);
			if (cmds)
				read_cmds(cmds, cmd_num);
			free(line);
			line = 0;
			free_cmds(cmds);
			cmds = 0;
		}
	}
	return (0);
}
