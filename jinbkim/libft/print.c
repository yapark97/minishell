/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/01 11:50:32 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_2d_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
	{
		ft_putstr(arr[i]);
		if (arr[i + 1])
			write(1, " ", 1);
	}
}

void	print_newline_2d_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		ft_putstr_newline(arr[i]);
}
