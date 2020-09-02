/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:41:53 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/10 19:52:41 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)ptr;
	while (i < num)
	{
		str[i] = value;
		i++;
	}
	return (str);
}
