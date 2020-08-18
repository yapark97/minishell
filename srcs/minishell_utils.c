/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapark <yapark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:11:39 by yapark            #+#    #+#             */
/*   Updated: 2020/07/21 13:39:33 by yapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
		return (0);
	if (*s1 == *s2)
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	else
		return (*s1 - *s2);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int	s1_len;

	i = -1;
	s1_len = ft_strlen(s1);
	while (s2[++i])
		s1[s1_len + i] = s2[i];
	s1[s1_len + i] = '\0';
	return (s1);
}
