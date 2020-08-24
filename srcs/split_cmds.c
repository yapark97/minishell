#include "minishell.h"

static int count_cmd_num(char *str, int quotes[], int idxs[][2])
{
    int i;
    int len;
    int cmd_num;

    i = -1;
    cmd_num = 0;
    len = 0;
    while (++i >= 0)
    {
        if (!str[i] || (str[i] == ';' && quotes[i] == 0))
        {
            if (!len && !str[i])
                break ;
            else if (!len)
                continue ;
            idxs[cmd_num][1] = len;
            idxs[cmd_num++][0] = i - len;
            len = 0;
            if (!str[i])
                break ;
        }
        else
            len++;
    }
    return (cmd_num);
}

static int  count_arg_num(char *str, int quotes[], int idxs[][2])
{
    int i;
    int len;
    int arg_num;

    i = -1;
    arg_num = 0;
    len = 0;
    while (++i >= 0)
    {
        if (!str[i] || ((str[i] == '|' || str[i] == '<' || str[i] == '>'
            || str[i] == ' ') && !quotes[i]))
        {
            if (!len && !str[i])
                break ;
            else if (!len && str[i] == ' ')
                continue ;
            if (len && (str[i] == '|' || str[i] == '<' || str[i] == '>'))
            {
                //abc 먼저 자르기
                idxs[arg_num][1] = len;
                idxs[arg_num++][0] = i - len;
            }
            if (str[i] == '|' || str[i] == '<' || str[i] == '>')
            {
                idxs[arg_num][1] = str[i + 1] == '>' ? 2 : 1;
                idxs[arg_num][0] = i;
                i = idxs[arg_num++][1] == 2 ? i + 1 : i;
            }
            else
            {
                idxs[arg_num][1] = len;
                idxs[arg_num++][0] = i - len;
            }
            len = 0;
            if (!str[i])
                break ;
        }
        else
            len++;
    }
    return (arg_num);
}

static char **split_arr(char *str, int num, int idxs[][2])
{
    char **ret;
    int i;

    ret = (char**)malloc(sizeof(char*) * (num + 1));
    i = -1;
    while (++i < num)
        ret[i] = ft_strndup(str + idxs[i][0], idxs[i][1]);
    ret[num] = 0;
    free(str);
    str = 0;
    return (ret);
}

char ***split_cmds(char *str, int quotes[])
{
    //norm 맞춰야함..
    int idxs[ft_strlen(str)][2];
    int cmd_num;
    char **temp;
    char ***ret;
    int i, j;
    int arg_num;
    int arg_quotes[ft_strlen(str)];
    int arg_idxs[ft_strlen(str)][2];

    cmd_num = count_cmd_num(str, quotes, idxs);  // 명령어 개수
    temp = split_arr(str, cmd_num, idxs);
    i = -1;
    ret = (char***)malloc(sizeof(char**) * (cmd_num + 1));
    while(++i < cmd_num)
    {
        j = 0;
        check_quotes(temp[i], arg_quotes, &j);
        arg_num = count_arg_num(temp[i], arg_quotes, arg_idxs);
        ret[i] = split_arr(temp[i], arg_num, arg_idxs);
    }
    free(temp);
    ret[cmd_num] = 0;
    extract_cmds(ret);
    return (ret);
}