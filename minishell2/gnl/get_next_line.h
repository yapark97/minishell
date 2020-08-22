/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:18:28 by yapark            #+#    #+#             */
/*   Updated: 2020/08/22 16:32:05 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32

typedef struct	s_file
{
	int			buf_idx;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
}				t_file;
int				get_next_line(int fd, char **line);
int				ft_strlen(const char *str);
char			*ft_strndup(char *str, int size);
char			*str_join_free(char *s1, char *s2, int free_s2);
int				index_of(char *str, char c);

#endif
