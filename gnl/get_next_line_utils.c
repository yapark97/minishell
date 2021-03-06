/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 18:36:18 by yapark            #+#    #+#             */
/*   Updated: 2020/08/22 16:32:25 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(char *str, int size)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char*)malloc(sizeof(char) * (size + 1));
	while (++i < size)
		ret[i] = str[i];
	ret[size] = '\0';
	return (ret);
}

char	*str_join_free(char *s1, char *s2, int free_s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = -1;
	while (++i < s1_len)
		ret[i] = s1[i];
	i--;
	while (++i < s1_len + s2_len)
		ret[i] = s2[i - s1_len];
	ret[i] = '\0';
	if (s1)
		free(s1);
	s1 = 0;
	if (s2 && free_s2)
		free(s2);
	s2 = 0;
	return (ret);
}

int		index_of(const char *str, char c)
{
	int i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
