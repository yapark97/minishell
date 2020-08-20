#include "minishell.h"

/*static char *remove_quote(char *str, int k)
{
    int i;
    int j;
    char *ret;

    ret = (char*)malloc(sizeof(char) * ft_strlen(str));
    i = 0;
    j = 0;
    while (str[j])
    {
        if (j != k)
            ret[i++] = str[j++];
        else
            j++;
    }
    free(str);
    ret[i] = '\0';
    return (ret);
}*/

static void parsing_echo(char **str, char *res, int *quote_flag, int *res_idx)
{
    int j;
    int k;

    j = -1;
    while (str[++j])
    {
        k = -1;
        while (str[j][++k])
        {
            if (str[j][k] == '"')
                *quote_flag *= -1;
            else
                res[(*res_idx)++] = str[j][k];
        }
    }
}

int do_echo(char ***cmds, int i)
{
    char res[BUF_SIZE];
    int quote_flag;
    int n_option_flag;
    int first_flag;
    int cmds_idx;
    int res_idx;
    char *line;
    char *temp[2];

    cmds_idx = i;
    res_idx = 0;
    n_option_flag = ft_strncmp(cmds[i][1], "-n", 3) == 0 ? 1 : 0;
    first_flag = n_option_flag + 1;
    while (1)
    {
        parsing_echo(cmds[cmds_idx] + first_flag, res, &quote_flag, &res_idx);
        first_flag = 0;
        if (quote_flag || !cmds[++cmds_idx])
            break;
    }
    while (quote_flag == -1)
    {
        ft_putstr("dquote> ");
        get_next_line(0, &line);
        temp[0] = line;
        temp[1] = 0;
        parsing_echo(temp, res, &quote_flag, &res_idx);
        if (line)
            free(line);
    }
    res[res_idx] = '\0';
    if (n_option_flag)
        ft_putstr(res);
    else
        ft_putstr_newline(res);
    return (cmds_idx - i);
}