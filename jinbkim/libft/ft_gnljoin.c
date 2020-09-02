/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnljoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/08/31 20:26:07 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnljoin(char *buff, char *temp)
{
	char	*data;
	int		i;
	int		j;

	if (!buff)
		return (NULL);
	if (!temp)
		return (buff);
	data = (char *)malloc(BUFFER_SIZE + ft_strlen(buff) + ft_strlen(temp) + 1);
	i = -1;
	while (buff[++i])
		data[i] = buff[i];
	j = -1;
	while (temp[++j])
		data[i + j] = temp[j];
	data[i + j] = '\0';
	free(buff);
	buff = NULL;
	return (data);
}
