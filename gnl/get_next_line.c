/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapark <yapark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:23:14 by yapark            #+#    #+#             */
/*   Updated: 2020/07/19 17:24:34 by yapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file(int fd, t_file *file)
{
	int		len;
	int		eof;
	int		nl_idx;

	eof = 1;
	nl_idx = -1;
	while (nl_idx == -1 && eof)
	{
		if ((len = read(fd, file->buf, BUFFER_SIZE)) < 0)
			return (-1);
		file->buf[len] = '\0';
		file->line = ft_strjoin(file->line, file->buf, 0);
		nl_idx = ft_strchr(file->line, '\n');
		if (len < BUFFER_SIZE && nl_idx == -1)
			eof = 0;
	}
	if (nl_idx != -1)
		(file->line)[nl_idx] = '\0';
	return (eof);
}

static int	update_file(int fd, t_file *file)
{
	int		new_buf_idx;
	int		eof;
	char	*temp;

	temp = 0;
	new_buf_idx = ft_strchr(file->buf + file->buf_idx + 1, '\n')
		+ file->buf_idx + 1;
	if (file->buf_idx > -1 && new_buf_idx > file->buf_idx)
	{
		file->line = ft_strncpy(file->buf + file->buf_idx + 1,
				new_buf_idx - file->buf_idx - 1);
		file->buf_idx = new_buf_idx;
		return (1);
	}
	if (file->buf_idx > -1)
	{
		temp = ft_strncpy(file->buf + file->buf_idx + 1,
				BUFFER_SIZE - file->buf_idx - 1);
	}
	if ((eof = read_file(fd, file)) == -1)
		return (eof);
	if (temp)
		file->line = ft_strjoin(temp, file->line, 1);
	file->buf_idx = ft_strchr(file->buf, '\n');
	return (eof);
}

int			get_next_line(int fd, char **line)
{
	static t_file	*file = 0;
	int				eof;

	if (BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!file)
	{
		file = (t_file*)malloc(sizeof(t_file));
		file->buf_idx = -1;
	}
	file->line = 0;
	if ((eof = update_file(fd, file)) == -1)
		return (eof);
	*line = ft_strncpy(file->line, ft_strlen(file->line));
	free(file->line);
	file->line = 0;
	if (eof == 0)
	{
		free(file);
		file = 0;
	}
	return (eof);
}
