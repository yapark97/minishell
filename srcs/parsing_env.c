#include "minishell.h"

void    parsing_env(char **envp)
{
    int i;
    int idx;

    i = -1;
    while (envp[++i])
    {
        idx = ft_strchr(envp[i], '=');
        g_env[i][0] = ft_strncpy(envp[i], idx);
        g_env[i][1] = ft_strncpy(envp[i] + idx + 1, ft_strlen(envp[i] + idx + 1));
    }
    g_env[i][0] = 0;
    g_env[i][1] = 0;
}