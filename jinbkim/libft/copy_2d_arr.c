/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2d_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/02 14:20:41 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_2d_arr(char **arr, int size)
{
	char	**ret;
	int		except;
	int		i;
	int		j;

	if (size == AUTO_SIZE)
		while (arr[size])
			size++;
	if (size == '_')
	{
		except = 1;
		size = MAX;
	}
	ret = (char**)malloc(sizeof(char*) * (size + 1));
	i = -1;
	j = -1;
	while (++i < size && arr[i])
		if (!(except == 1 && !ft_strncmp(arr[i], "_=", 2)))
			ret[++j] = ft_strdup(arr[i]);
	ret[++j] = 0;
	return (ret);
}
