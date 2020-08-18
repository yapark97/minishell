/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cd_ls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapark <yapark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:11:57 by yapark            #+#    #+#             */
/*   Updated: 2020/07/21 16:30:31 by yapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	errno;

int			do_cd(char *line)
{
	char *err_msg;

	if (chdir(line) == -1)
	{
		err_msg = strerror(errno);
		write(1, err_msg, ft_strlen(err_msg));
		write(1, "\n", 1);
	}
	return (0);
}
