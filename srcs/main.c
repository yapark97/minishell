#include "minishell.h"

/*static void print_cmds(char ***cmds)
{
    int i = -1;
    int j;

    while (cmds[++i])
    {
        j = -1;
        while (cmds[i][++j])
        {

            ft_putstr(cmds[i][j]);
            write(1, "/", 1);
        }
        write(1, "\n", 1);
    }
}*/

int main(int argc, char **argv, char **envp)
{
    char *line;
    char ***cmds;


    (void)argc;
    (void)argv;
    g_envp = copy_2d_arr(envp, MAX);
    catch_signals();
    while (1)
    {
        ft_putstr("minishell$ ");
        if (!get_next_line(0, &line) && line[0] == '\0')
            exit_minishell(0);
        cmds = parsing_cmds(line); //line freed here
        exec_cmds(cmds);
        //print_cmds(cmds);
        free_3d_arr(cmds);
    }
    return (0);
}