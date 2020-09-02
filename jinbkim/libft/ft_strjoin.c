/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:50:53 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/08 19:37:47 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*data;
	int		size;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = -1;
	data = (char *)malloc(sizeof(char) * size + 1);
	if (data == NULL)
		return (NULL);
	while (s1[++i])
		data[i] = s1[i];
	while (s2[++j])
		data[i + j] = s2[j];
	data[i + j] = '\0';
	return (data);
}
