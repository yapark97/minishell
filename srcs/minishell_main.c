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
	(void)sig_num;
	sigflag = 1;
	ft_putstr("\nminishell$ ");
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

static int	read_cmds(char ***cmds, int cmd_num, int pre_exit_code)
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
		else if (ft_strncmp(cmds[i][0], "$?", 3) == 0)
		{
			ft_putnbr(pre_exit_code);
			ft_putstr_newline(": command not found");
		}
		else
			pre_exit_code = try_execute(cmds[i]);
	}
	return (pre_exit_code);
}

int			main(void)
{
	char	*line;
	char	***cmds;
	int		cmd_num;
	int		pre_exit_code;

	pre_exit_code = 0;
	line = 0;
	signal(SIGINT, catch_int);
	while (1)
	{
		if (sigflag == 0)
			ft_putstr("minishell$ ");
		else
			sigflag = 0;
		if (get_next_line(0, &line) < 0)
			break ;
		if (line)
		{
			cmds = parsing_cmds(line, &cmd_num);
			if (cmds)
				pre_exit_code = read_cmds(cmds, cmd_num, pre_exit_code);
			free(line);
			line = 0;
			free_cmds(cmds);
			cmds = 0;
		}
	}
	return (0);
}
