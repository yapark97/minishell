/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:59:18 by jinbkim           #+#    #+#             */
/*   Updated: 2020/08/31 20:41:33 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sign_check2(long *n)
{
	if (*n >= 0)
		return (1);
	*n *= -1;
	return (2);
}

int		num_len(long n)
{
	int result;

	result = 1;
	while (n >= 10)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;
	int		i;
	int		size;
	long	num;

	num = n;
	sign = sign_check2(&num);
	size = num_len(num);
	str = (char *)malloc((sizeof(char) * size) + sign);
	if (str == NULL)
		return (NULL);
	str[size + sign - 1] = '\0';
	if (sign == 2)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	i = 0;
	while (num > 0)
	{
		str[size + sign - i - 2] = num % 10 + '0';
		num /= 10;
		i++;
	}
	return (str);
}
