/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/05 21:14:53 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_s(char const *s, char c)
{
	int value;
	int i;
	int j;

	value = 0;
	i = 0;
	j = ft_strlen(s);
	while (s[i] == c && s[i])
		i++;
	while (s[j] && s[j] == c && j > 0)
		j--;
	if (i > j)
		return (0);
	while (i <= j)
	{
		if (s[i] != c)
			i++;
		else
		{
			while (s[i] == c)
				i++;
			value++;
		}
	}
	return (value);
}

char	**free_func(char **data, int i)
{
	while (i >= 0)
	{
		free(data[i]);
		data[i--] = NULL;
	}
	free(data);
	data = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**data;
	int		i;
	int		size;

	if (!s || !(data = (char **)malloc(sizeof(char *) * (count_s(s, c) + 2))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size = 0;
			while (*(s + size) != c && *(s + size))
				size++;
			if (!(data[i] = ft_substr(s, 0, size)))
				return (free_func(data, i));
			s += size;
			i++;
		}
	}
	data[i] = NULL;
	return (data);
}
