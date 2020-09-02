/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:11:11 by yapark            #+#    #+#             */
/*   Updated: 2020/09/02 11:43:43 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NOTHING	-1
# define AUTO_SIZE	0
# define FILE_SIZE	1024
# define MAX		1000

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(const char *s);
void	ft_putstr_newline(const char *s);
void	ft_putnbr(int n);
void	free_2d_arr(char **arr);
void	free_3d_arr(char ***arr);
void	free_init(char **data, char *init);

void	*ft_memset(void *ptr, int value, size_t num);
void	print_2d_arr(char **arr);
void	print_newline_2d_arr(char **arr);

char	*ft_gnljoin(char *buff, char *temp);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(char *str, int size);

char	**ft_split(char const *s, char c);
char	**ft_split_one(char *str, char c);
char	**copy_2d_arr(char **arr, int size);

int		ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
int		ft_strchr(char *str, char c);
int		ft_strcmp(const char *s1, const char *s2);

#endif
