#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    char *line;

    (void)argc;
    (void)argv;
    g_envp = envp;
    catch_signals();
    while (1)
    {
        ft_putstr("minishell$ ");
        if (!get_next_line(0, &line) && line[0] == '\0')
            exit_minishell();
        printf("%s\n", line);
        free(line);
    }
    
    return (0);
}