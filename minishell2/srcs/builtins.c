#include "minishell.h"

extern int  errno;

static void do_cd(char **argv)
{
    char *err_msg;

    if (!argv)
    {
        chdir("/");
        return ;
    }
    if (argv[2])
    {
        ft_putstr_newline("minishell: cd: too many arguments");
        return ;
    }
    if (chdir(argv[1]) == -1)
    {
        err_msg = strerror(errno);
        ft_putstr("minishell: cd: ");
        ft_putstr(argv[1]);
        ft_putstr(": ");
        ft_putstr_newline(err_msg);
    }
}

static void do_env()
{
    int i;

    i = -1;
    while (g_envp[++i] && g_envp[i][0])
        ft_putstr_newline(g_envp[i]);
}

static void do_export(char **argv)
{
    int i;
    int j;
    int idx;
    int found;

    i = 0;
    while (argv[++i])
    {
        found = 0;
        if ((idx = index_of(argv[i], '=')) == -1)
            continue ;
        else if (idx == 0)
        {
            ft_putstr("minishell: export: '");
            ft_putstr(argv[i]);
            ft_putstr_newline("': not a valid identifier");
            continue ;
        }
        j = -1;
        while (g_envp[++j])
        {
            if (!ft_strncmp(argv[i], g_envp[j], index_of(g_envp[j], '='))
                && index_of(argv[i], '=') == index_of(g_envp[j], '='))
            {
                ft_strcpy(g_envp[j], argv[i]);
                found = 1;
                break ;
            }
        }
        if (!found)
            add_2d_arr(g_envp, ft_strdup(argv[i]));
    }
}

static void do_unset(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[++i])
    {
        j = -1;
        while (g_envp[++j])
        {
            if (!ft_strncmp(argv[i], g_envp[j], index_of(g_envp[j], '='))
                && ft_strlen(argv[i]) == index_of(g_envp[j], '='))
            {
                g_envp[j][0] = '\0';
                break ;
            }
        }
    }
}

int         builtins(int fd, char **argv, char ***cmds)
{
    (void)fd;
    if (!ft_strcmp(argv[0], "echo") || (!ft_strcmp(argv[0], "pwd")))
        excutables(fd, 0, argv);
    else if (!ft_strcmp(argv[0], "cd"))
        do_cd(argv);
    else if (!ft_strcmp(argv[0], "exit"))
        exit_minishell(cmds);
    else if (!ft_strcmp(argv[0], "env"))
        do_env();
    else if (!ft_strcmp(argv[0], "export"))
        do_export(argv);
    else if (!ft_strcmp(argv[0], "unset"))
        do_unset(argv);
    else
        return (0);
    return (1);
}