/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 19:36:34 by jinbkim           #+#    #+#             */
/*   Updated: 2020/08/30 19:22:38 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_newline(char *temp)
{
	unsigned int i;

	i = -1;
	while (temp[++i])
		if (temp[i] == '\n')
			return (i);
	return (-1);
}

char	*split_join1(char *buff, int i, char **line)
{
	char *data;

	buff[i] = '\0';
	*line = ft_strdup(buff);
	data = ft_strdup(buff + i + 1);
	free(buff);
	buff = NULL;
	return (data);
}

char	*split_join2(char *buff, char *temp, int i, char **line)
{
	char *data;

	temp[i] = '\0';
	buff = ft_gnljoin(buff, temp);
	*line = ft_strdup(buff);
	data = ft_strdup(temp + i + 1);
	free(buff);
	free(temp);
	buff = NULL;
	temp = NULL;
	return (data);
}

int		before_gnl(int fd, char **line, char **buff, char **temp)
{
	int new_line_i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (buff[fd] == NULL)
		buff[fd] = ft_strdup("\0");
	if ((new_line_i = find_newline(buff[fd])) >= 0)
	{
		buff[fd] = split_join1(buff[fd], new_line_i, line);
		return (1);
	}
	*temp = (char*)malloc(BUFFER_SIZE + 1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buff[FILE_SIZE];
	char		*temp;
	int			idx;
	int			ret;

	if ((ret = before_gnl(fd, line, buff, &temp)) != 0)
		return (ret);
	while ((ret = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[ret] = '\0';
		if ((idx = find_newline(temp)) >= 0)
		{
			buff[fd] = split_join2(buff[fd], temp, idx, line);
			return (1);
		}
		buff[fd] = ft_gnljoin(buff[fd], temp);
	}
	*line = ft_strdup(buff[fd]);
	free(buff[fd]);
	free(temp);
	buff[fd] = NULL;
	temp = NULL;
	if (ret < 0)
		return (-1);
	return (0);
}
