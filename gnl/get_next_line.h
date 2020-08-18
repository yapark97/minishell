/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yapark <yapark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 15:18:28 by yapark            #+#    #+#             */
/*   Updated: 2020/07/19 16:37:19 by yapark           ###   ########.fr       */
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
int				ft_strlen(char *str);
char			*ft_strncpy(char *str, int size);
char			*ft_strjoin(char *s1, char *s2, int free_s2);
int				ft_strchr(char *str, char c);

#endif
