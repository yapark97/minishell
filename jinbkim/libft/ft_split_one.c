/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/08/30 19:21:07 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_one(char *str, char c)
{
	char	**data;
	int		i;

	data = (char **)malloc(sizeof(char *) * 3);
	i = ft_strchr(str, c);
	data[0] = ft_strndup(str, i);
	data[1] = ft_strdup(str + i + 1);
	data[2] = NULL;
	return (data);
}
