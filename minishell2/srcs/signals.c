#include "minishell.h"

static void catch_sigint()
{
    ft_putstr("\nminishell$ ");
}

static void catch_sigquit()
{
    
}

void catch_signals()
{
    signal(SIGINT, catch_sigint);
    signal(SIGQUIT, catch_sigquit);
}