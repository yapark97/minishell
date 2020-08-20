/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:11:11 by yapark            #+#    #+#             */
/*   Updated: 2020/08/18 15:30:14 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <errno.h>

int		get_next_line(int fd, char **line);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
char	*ft_strcat(char *s1, const char *s2);
int		do_cd(char *line);
char	**ft_split(char const *s, char c);
char	***parsing_cmds(char *line, int *cmd_num);
void	builtins(char **cmd);
int		try_execute(char **cmd);
void	ft_putstr(char *s);
void	ft_putstr_newline(char *s);
void    ft_putnbr(int n);
char    *ft_strdup(const char *s);
int do_echo(char ***cmds, int i);

# define BUF_SIZE 1000

#endif
