#include "minishell.h"

static int search_env(char *key)
{
    int i;

    i = -1;
    while (g_env[++i][0])
    {
        if (ft_strncmp(g_env[i][0], key, ft_strlen(key) + 1) == 0)
        {
            free(g_env[i][1]);
            free(key);
            g_env[i][1] = 0;
            key = 0;
            return (i);
        }
    }
    g_env[i][0] = key;
    return (i);
}

void do_export(char *str)
{
    int env_idx;
    int equal_sign_idx;
    char *key;
    char *value;

    equal_sign_idx = ft_strchr(str, '=');
    key = ft_strncpy(str, equal_sign_idx);
    value = ft_strncpy(str + equal_sign_idx + 1, ft_strlen(str + equal_sign_idx + 1));
    env_idx = search_env(key);
    g_env[env_idx][1] = value;
}

void do_unset(char *str)
{
    int i;

    i = -1;
    while (g_env[++i][0])
    {
        if (ft_strncmp(g_env[i][0], str, ft_strlen(str) + 1) == 0)
            g_env[i][0][0] = '\0';
    }
}

void do_env()
{
    int i;

    i = -1;
    while (g_env[++i][0])
    {
        if (g_env[i][0][0] == '\0')
            continue ;
        ft_putstr(g_env[i][0]);
        ft_putstr("=");
        ft_putstr_newline(g_env[i][1]);
    }
}