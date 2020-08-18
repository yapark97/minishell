/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:11:57 by yapark            #+#    #+#             */
/*   Updated: 2020/08/18 15:40:19 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	errno;

int			do_cd(char *line)
{
	char *err_msg;

	if (chdir(line) == -1 && line)
	{
		err_msg = strerror(errno);
		ft_putstr("-bash: cd: ");
		ft_putstr(line);
		ft_putstr(": ");
		ft_putstr_newline(err_msg);
	}
	return (0);
}
