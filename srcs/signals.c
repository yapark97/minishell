#include "minishell.h"

static void catch_sigint()
{
    ft_putstr("\nminishell$ ");
}

static void catch_sigquit()
{
    ft_putstr("Quit: 3\nminishell$ ");
}

void catch_signals()
{
    signal(SIGINT, catch_sigint);
    signal(SIGQUIT, catch_sigquit);
}