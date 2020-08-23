#include "minishell.h"

static char ***unexpected_eof_error(int k, char *s1, char *s2)
{
    ft_putstr("bash: unexpected EOF while looking for matching ");
    if (k == 2)
        ft_putstr_newline("'\"'\nbash: syntax error: unexpected end of file");
    else
        ft_putstr_newline("'''\nbash: syntax error: unexpected end of file");
    if (s1)
    {
        free(s1);
        s1 = 0;
    }
    if (s2)
    {
        free(s2);
        s2 = 0;
    }
    return (0);
}

void check_quotes(char *str, int quotes[], int *idx)
{
    int prec;

    while (str[*idx])
    {
        prec = *idx == 0 ? 0 : quotes[*idx - 1];
        if (str[*idx] == '"' && (prec == 0 || prec == 3 || prec == -3))
            quotes[*idx] = 1;
        else if (str[*idx] == '"' && prec > 0)
            quotes[*idx] = 3;
        else if (str[*idx] == '"')
            quotes[*idx] = -2;
        else if (str[*idx] == '\'' && (prec == 0 || prec == 3 || prec == -3))
            quotes[*idx] = -1;
        else if (str[*idx] == '\'' && prec < 0)
            quotes[*idx] = -3;
        else if (str[*idx] == '\'')
            quotes[*idx] = 2;
        else if (prec == 2 || prec == -2)
            quotes[*idx] = prec;
        else
            quotes[*idx] = (prec == 3 || prec == -3) ? 0 : prec * 2;
        (*idx)++;
    }
}

char ***parsing_cmds(char *str)
{
    int quotes[MAX]; //00000122222230000000-1-2-2-2-2-300000
    int q_idx;
    char *line;
    char *temp;

    q_idx = 0;
    check_quotes(str, quotes, &q_idx);
    while (quotes[q_idx - 1] == 2 || quotes[q_idx - 1] == -2 || quotes[q_idx - 1] == 1 || quotes[q_idx - 1] == -1)
    {
        ft_putstr("dquote> ");
        if (!get_next_line(0, &line) && line[0] == '\0')
            return (unexpected_eof_error(quotes[q_idx - 1], line, str));
        temp = ft_strjoin("\n", line);
        free(line);
        line = temp;
        temp = ft_strjoin(str, line);
        free(line);
        free(str);
        str = temp;
        check_quotes(str, quotes, &q_idx);
    }
    return (split_cmds(str, quotes));
}