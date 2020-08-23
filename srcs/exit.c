#include "minishell.h"

void free_2d_arr(char **arr)
{
    int i;

    i = -1;
    while (arr[++i])
        free(arr[i]);
    free(arr);
}

void free_3d_arr(char ***arr)
{
    int i;

    i = -1;
    while (arr[++i])
        free_2d_arr(arr[i]);
    free(arr);
}

void exit_minishell(char ***cmds)
{
    if (cmds)
        free_3d_arr(cmds);
    free_2d_arr(g_envp);
    ft_putstr_newline("exit");
    exit(0);
}