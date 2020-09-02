/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/02 16:55:36 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_init(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	ft_memset(g_except, 0, sizeof(int) * EX_END);
	g_envp = copy_2d_arr(envp, MAX);
	catch_signals();
}

void	exit_minishell(char ***cmds)
{
	if (cmds)
		free_3d_arr(cmds);
	free_2d_arr(g_envp);
	ft_putstr_newline("exit");
	exit(0);
}

int		main(int argc, char **argv, char **envp)
{
	char *line;
	char ***cmds;

	minishell_init(argc, argv, envp);
	while (1)
	{
		ft_putstr("minishell$ ");
		if (!get_next_line(0, &line))
			exit_minishell(0);
		cmds = parsing_cmds(line);
		exec_cmds(cmds);
		free_3d_arr(cmds);
	}
	return (0);
}
