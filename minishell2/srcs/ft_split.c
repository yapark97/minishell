/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapark <yapark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 15:18:01 by yapark            #+#    #+#             */
/*   Updated: 2020/07/21 12:12:13 by yapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_word(char const *s, char c, int *idx, int *len)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	idx[0] = 0;
	while (1)
	{
		if ((s[i] == c || s[i] == '\0') && i > idx[ret])
		{
			if (s[i] != '\0')
				idx[ret + 1] = i + 1;
			len[ret] = i - idx[ret];
			ret++;
		}
		else if (s[i] == c)
			idx[ret]++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (ret);
}

static char	**set_ret_arr(int *len, int word_num)
{
	int		i;
	int		j;
	char	**ret;

	i = -1;
	if (!(ret = (char**)malloc(sizeof(char*) * (word_num + 1))))
		return ((char**)0);
	while (++i < word_num)
	{
		if (!(ret[i] = (char*)malloc(sizeof(char) * (len[i] + 1))))
		{
			j = -1;
			while (++j < i)
				free(ret[j]);
			free(ret);
			return ((char**)0);
		}
	}
	return (ret);
}

/*static char	**empty_str(void)
{
	char **ret;

	if (!(ret = (char**)malloc(sizeof(char*))))
		return ((char**)0);
	ret[0] = 0;
	return (ret);
}*/

char		**ft_split(char const *s, char c)
{
	int		word_index[2][ft_strlen(s)];
	int		word_num;
	int		i;
	int		j;
	char	**ret;

	if (s == 0)
		return ((char**)0);
	if (*s == 0)
		return ((char**)0);
	word_num = find_word(s, c, word_index[0], word_index[1]);
	i = -1;
	if (!(ret = set_ret_arr(word_index[1], word_num)))
		return ((char**)0);
	i = -1;
	while (++i < word_num)
	{
		j = -1;
		while (++j < word_index[1][i])
			ret[i][j] = s[word_index[0][i] + j];
		ret[i][j] = '\0';
	}
	ret[word_num] = 0;
	return (ret);
}
