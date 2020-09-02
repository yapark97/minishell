/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/02 16:06:28 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_cmd_num(char *str, int quotes[], int idxs[][2])
{
	int i;
	int len;
	int cmd_num;

	i = -1;
	cmd_num = 0;
	len = 0;
	while (++i >= 0)
	{
		if (!str[i] || (str[i] == ';' && quotes[i] == OUT))
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

void	replace_env(char **str)
{
	int quotes[MAX];
	int dolor_i;
	int idx;
	int i;

	if ((dolor_i = ft_strchr(*str, '$')) == NOTHING)
		return ;
	if (!ft_strcmp(str[0], "$?"))
	{
		free_init(&str[0], ft_itoa(g_exit_code));
		return ;
	}
	i = 0;
	check_quotes(*str, quotes, &i);
	i = -1;
	while (g_envp[++i])
	{
		idx = ft_strchr(g_envp[i], '=');
		if (!ft_strncmp((*str) + dolor_i + 1, g_envp[i], idx)
			&& quotes[dolor_i] >= OUT)
		{
			free_init(str, ft_strdup(g_envp[i] + idx + 1));
			break ;
		}
	}
}

void	remove_quotes(char **str)
{
	char	buf[MAX];
	int		i;
	int		j;
	int		flag;

	i = -1;
	j = -1;
	flag = 0;
	while (str[0][++i])
	{
		if (str[0][i] == '"' && flag == 0)
			flag = 1;
		else if (str[0][i] == '"' && flag == 1)
			flag = 0;
		else if (str[0][i] == '\'' && flag == 0)
			flag = -1;
		else if (str[0][i] == '\'' && flag == -1)
			flag = 0;
		else
			buf[++j] = str[0][i];
	}
	buf[++j] = 0;
	free_init(&str[0], ft_strdup(buf));
}

void	extract_cmds(char ***cmds)
{
	int i;
	int j;

	i = -1;
	while (cmds[++i])
	{
		j = -1;
		while (cmds[i][++j])
		{
			replace_env(&cmds[i][j]);
			remove_quotes(&cmds[i][j]);
		}
	}
}

char	***split_cmds(char *str, int quotes[])
{
	char	***ret;
	int		idxs[ft_strlen(str)][2];
	int		cmd_num;

	cmd_num = count_cmd_num(str, quotes, idxs);
	ret = (char ***)malloc(sizeof(char **) * (cmd_num + 1));
	split_one_more(str, cmd_num, idxs, ret);
	ret[cmd_num] = 0;
	extract_cmds(ret);
	return (ret);
}
