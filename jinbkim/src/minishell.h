/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:11:11 by yapark            #+#    #+#             */
/*   Updated: 2020/09/02 17:44:36 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

enum	e_quotes
{
	Q_E = -3,
	Q_B,
	Q_S,
	OUT,
	DQ_S,
	DQ_B,
	DQ_E
};

enum	e_except
{
	NONE,
	SYNTAX,
	EX_END
};

char **g_envp;
int g_exit_code;
int g_except[EX_END];

void	exit_minishell(char ***cmds);
void	check_quotes(char *str, int quotes[], int *i);
void	split_one_more(char *str, int cmd_num, int idxs[][2], char ***ret);
void	exec_cmds(char ***cmds);
void	do_unset(char **argv);
void	do_export(char **argv);
void	catch_signals();

int		redirections(char **cmd);
int		excutables(int fd_o, int fd_i, char **argv);
int		pipes(char **cmd);
int		builtins(char **argv, char ***cmds);

char	*find_path(char *cmd);

char	***parsing_cmds(char *str);
char	***split_cmds(char *str, int quotes[]);

#endif
