#include "minishell.h"

static void replace_env(char **str)
{
    int i;
    int idx;

    if (*str[0] != '$')
        return;
    i = -1;
    while (g_envp[++i])
    {
        idx = index_of(g_envp[i], '=');
        if (ft_strncmp(&((*str)[1]), g_envp[i], idx) == 0 && ft_strlen(*str) - 1 == idx)
        {
            free(*str);
            *str = ft_strdup(g_envp[i] + idx + 1);
            return;
        }
    }
}

static void remove_quotes(char **str)
{
    int i;
    int j;
    int flag;
    char buf[MAX];

    i = -1;
    j = -1;
    flag = 0;
    while (str[0][++i])
    {
        if (str[0][i] == '"' && flag == 0)
            flag = 1;
        else if (str[0][i] == '"' && flag == 1)
            flag = 0;
        else if (str[0][i] == '\'' && flag == 0)
            flag = -1;
        else if (str[0][i] == '\'' && flag == -1)
            flag = 0;
        else
            buf[++j] = str[0][i];
    }
    buf[++j] = 0;
    free(str[0]);
    str[0] = ft_strdup(buf);
}

void extract_cmds(char ***cmds)
{
    int i;
    int j;

    i = -1;
    while (cmds[++i])
    {
        j = -1;
        while (cmds[i][++j])
        {
            replace_env(&cmds[i][j]);
            remove_quotes(&cmds[i][j]);
        }
    }
}