/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/02 11:54:24 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_quotes(char *str, int quotes[], int *i)
{
	int pre;

	while (str[*i])
	{
		pre = *i == 0 ? OUT : quotes[*i - 1];
		if (str[*i] == '"' && (pre == OUT || pre == DQ_E || pre == Q_E))
			quotes[*i] = DQ_S;
		else if (str[*i] == '"' && pre > OUT)
			quotes[*i] = DQ_E;
		else if (str[*i] == '"')
			quotes[*i] = Q_B;
		else if (str[*i] == '\'' && (pre == OUT || pre == DQ_E || pre == Q_E))
			quotes[*i] = Q_S;
		else if (str[*i] == '\'' && pre < OUT)
			quotes[*i] = Q_E;
		else if (str[*i] == '\'')
			quotes[*i] = DQ_B;
		else if (pre == DQ_B || pre == Q_B)
			quotes[*i] = pre;
		else
			quotes[*i] = (pre == DQ_E || pre == Q_E) ? OUT : pre * 2;
		(*i)++;
	}
}

char	***unexpected_eof_error(char *s1, char *s2)
{
	ft_putstr_newline("");
	free_init(&s1, NULL);
	free_init(&s2, NULL);
	return (0);
}

char	***parsing_cmds(char *str)
{
	int		quotes[MAX];
	int		q_idx;
	char	*line;

	if (!str[0])
	{
		free_init(&str, NULL);
		return (NULL);
	}
	q_idx = 0;
	check_quotes(str, quotes, &q_idx);
	while (quotes[q_idx - 1] == DQ_B || quotes[q_idx - 1] == Q_B
		|| quotes[q_idx - 1] == DQ_S || quotes[q_idx - 1] == Q_S)
	{
		if (quotes[q_idx - 1] > OUT)
			ft_putstr("d");
		ft_putstr("quote> ");
		if (!get_next_line(0, &line))
			return (unexpected_eof_error(line, str));
		str = ft_gnljoin(str, "\n");
		str = ft_gnljoin(str, line);
		free_init(&line, NULL);
		check_quotes(str, quotes, &q_idx);
	}
	return (split_cmds(str, quotes));
}
