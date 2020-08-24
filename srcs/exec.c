#include "minishell.h"

static void redir_out(char **cmd, const char *file, int overwrite)
{
    int     fd;

    if (overwrite)
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    else
        fd = open(file, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);

    excutables(fd, 0, cmd);
    close(fd);
}

static void redir_in(char **cmd, const char *file)
{
    int fd;

    if ((fd = open(file, O_RDONLY)) == -1)
    {
        ft_putstr("bash: ");
        ft_putstr(file);
        ft_putstr_newline(": No such file or directory");
        return ;
    }
    excutables(1, fd, cmd);
    close(fd);
}

static int redirections(char **cmd)
{
    int i;
    char **cmd_cpy;

    i = -1;
    cmd_cpy = 0;
    while (cmd[++i])
    {
        if (!ft_strcmp(cmd[i], "<") || !ft_strcmp(cmd[i], ">") || !ft_strcmp(cmd[i], ">>"))
            cmd_cpy = copy_2d_arr(cmd, i);
        if (!ft_strcmp(cmd[i], "<"))
            redir_in(cmd_cpy, cmd[i + 1]);
        else if (!ft_strcmp(cmd[i], ">"))
            redir_out(cmd_cpy, cmd[i + 1], 1);
        else if (!ft_strcmp(cmd[i], ">>"))
            redir_out(cmd_cpy, cmd[i + 1], 0);
        if (cmd_cpy)
        {
            free_2d_arr(cmd_cpy);
            return (1);
        }
    }
    return (0);
}

static int pipes(char **cmd)
{
    int i;
    char **cmd1;
    char **cmd2;

    i = -1;
    cmd1 = 0;
    cmd2 = 0;
    while (cmd[++i])
    {
        if (!ft_strcmp(cmd[i], "|"))
        {
            cmd1 = copy_2d_arr(cmd, i);
            cmd2 = copy_2d_arr(&cmd[i + 1], -1);
            pipes_exec(cmd1, cmd2);
            free_2d_arr(cmd1);
            free_2d_arr(cmd2);
            return (1);
        }
    }
    return (0);
}

void exec_cmds(char ***cmds)
{
    int i;

    i = -1;
    while (cmds[++i])
    {
        if (redirections(cmds[i]) ||
            pipes(cmds[i]) ||
            builtins(1, cmds[i], cmds) ||
            excutables(1, 0, cmds[i]))
        {

        }
        else
        {
            ft_putstr("minishell: ");
            print_2d_arr(cmds[i]);
            ft_putstr_newline(": command not found");
            exit(1); //자식프로세스종료
        }

    }
}