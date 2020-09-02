/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/02 11:44:29 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_2d_arr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_3d_arr(char ***arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free_2d_arr(arr[i]);
	free(arr);
}

void	free_init(char **data, char *init)
{
	free(*data);
	*data = init;
}
