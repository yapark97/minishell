#include "minishell.h"

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putstr_newline(const char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int s1_len;
	int s2_len;
	int i;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = -1;
	while (++i < s1_len)
		ret[i] = s1[i];
	i--;
	while (++i < s1_len + s2_len)
		ret[i] = s2[i - s1_len];
	ret[i] = '\0';
	return (ret);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2 || (!*s1 && !*s2))
		return (*s1 - *s2);
	return (ft_strcmp(s1 + 1, s2 + 1));
}

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	if (n == 0)
		return (0);
	if (*s1 != *s2 || (!*s1 && !*s2))
		return (*s1 - *s2);
	return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (0);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	return (dst);
}

char	**copy_2d_arr(char **arr, int size)
{
	char	**ret;
	int		i;

	if (size == -1)
	{
		while (arr[++size])
			;
	}
	ret = (char**)malloc(sizeof(char*) * (size + 1));
	i = -1;
	while (++i < size && arr[i])
		ret[i] = ft_strdup(arr[i]);
	ret[i] = 0;
	return (ret);
}

char *ft_itoa(int k)
{
	int i;
	int j;
	int temp;
	char *ret;

	i = 1;
	temp = k;
	while (temp > 9)
	{
		i++;
		temp = temp / 10;
	}
	ret = (char*)malloc(sizeof(char) * (i + 1));
	ret[i] = 0;
	j = i;
	temp = k;
	while (--j >= 0)
	{
		ret[j] = temp % 10 + '0';
		temp = temp / 10;
	}
	return (ret);
}

void	print_2d_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
	{
		ft_putstr(arr[i]);
		if (arr[i + i])
			write(1, " ", 1);
	}
}

/*void	add_2d_arr(char **arr, char *str)
{
	int i;

	i = -1;
	while (arr[++i])
		;
	arr[i++] = str;
	arr[i] = 0;
}

void	delete_2d_arr(char **arr, int i)
{
	free(arr[i]);
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i++;
	}
}*/