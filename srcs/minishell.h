#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include "../gnl/get_next_line.h"

# define MAX 1000

char **g_envp;
int g_exit_code;

//signals.c
void catch_signals(void);

//parcing cmds ~
char ***parsing_cmds(char *str);
char ***split_cmds(char *str, int quotes[]);
void check_quotes(char *str, int quotes[], int *idx);
void extract_cmds(char ***cmds);

//exec & builtins
void exec_cmds(char ***cmds);
int builtins(int fd, char **argv, char ***cmds);
void pipes_exec(char **cmd1, char **cmd2);
int excutables(int fd_o, int fd_i, char **argv);

//exit.c
void exit_minishell(char ***cmds);
void free_2d_arr(char **arr);
void free_3d_arr(char ***arr);

//minishell_utils.c
void	ft_putstr(const char *s);
void	ft_putstr_newline(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	**copy_2d_arr(char **arr, int size);
void	print_2d_arr(char **arr);
//void	add_2d_arr(char **arr, char *str);
//void	delete_2d_arr(char **arr, int i);
char	**ft_split(char const *s, char c);
char    *ft_itoa(int k);

#endif