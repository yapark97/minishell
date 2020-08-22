#include "minishell.h"

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putstr_newline(char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}