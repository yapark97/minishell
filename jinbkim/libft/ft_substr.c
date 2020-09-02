/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:01:07 by jinbkim           #+#    #+#             */
/*   Updated: 2020/08/21 13:29:17 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*data;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = -1;
	data = (char *)malloc((sizeof(char) * len) + 1);
	if (data == NULL)
		return (NULL);
	if (ft_strlen(s) < (int)start)
	{
		data[0] = '\0';
		return (data);
	}
	while (++i < len)
		data[i] = s[start++];
	data[i] = '\0';
	return (data);
}
