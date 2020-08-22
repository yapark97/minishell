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
# include "../gnl/get_next_line.h"

char **g_envp;

//signals.c
void catch_signals(void);

//exit.c
void exit_minishell(void);

//minishell_utils.c
void	ft_putstr(char *s);
void	ft_putstr_newline(char *s);

#endif