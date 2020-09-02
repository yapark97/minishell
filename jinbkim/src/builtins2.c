/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:46:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/09/02 11:16:46 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**sort_env(void)
{
	char	**export;
	char	*temp;
	int		i;
	int		j;

	export = copy_2d_arr(g_envp, '_');
	i = -1;
	while (export[++i])
	{
		j = -1;
		while (export[++j + 1])
		{
			if (ft_strcmp(export[j], export[j + 1]) > 0)
			{
				temp = export[j];
				export[j] = export[j + 1];
				export[j + 1] = temp;
				i = -1;
			}
		}
	}
	return (export);
}

void	only_export(void)
{
	char	**export;
	char	**new_export;
	char	**split_export;
	int		i;

	export = sort_env();
	i = -1;
	new_export = (char **)malloc(sizeof(char *) * MAX);
	while (export[++i])
	{
		split_export = ft_split_one(export[i], '=');
		new_export[i] = ft_strjoin("declare -x ", split_export[0]);
		new_export[i] = ft_gnljoin(new_export[i], "=\"");
		new_export[i] = ft_gnljoin(new_export[i], split_export[1]);
		new_export[i] = ft_gnljoin(new_export[i], "\"");
		free_2d_arr(split_export);
	}
	new_export[i] = NULL;
	print_newline_2d_arr(new_export);
	free_2d_arr(export);
	free_2d_arr(new_export);
}

void	use_export(char **argv, int *i)
{
	int found;
	int j;

	found = 0;
	j = -1;
	while (g_envp[++j])
	{
		if (!ft_strncmp(argv[*i], g_envp[j], ft_strchr(g_envp[j], '='))
			&& ft_strchr(argv[*i], '=') == ft_strchr(g_envp[j], '='))
		{
			free(g_envp[j]);
			g_envp[j] = ft_strdup(argv[*i]);
			found = 1;
			break ;
		}
	}
	if (!found)
	{
		g_envp[j] = ft_strdup(argv[*i]);
		g_envp[j + 1] = 0;
	}
}

void	do_export(char **argv)
{
	int i;
	int idx;

	if (!argv[1])
		only_export();
	i = 0;
	while (argv[++i])
	{
		if ((idx = ft_strchr(argv[i], '=')) == -1)
			continue;
		else if (idx == 0)
		{
			ft_putstr("-minishell: export: '");
			ft_putstr(argv[i]);
			ft_putstr_newline("': not a valid identifier");
			continue;
		}
		use_export(argv, &i);
	}
}

void	do_unset(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (g_envp[++j])
		{
			if (!ft_strncmp(argv[i], g_envp[j], ft_strchr(g_envp[j], '='))
				&& ft_strlen(argv[i]) == ft_strchr(g_envp[j], '='))
			{
				free(g_envp[j--]);
				while (g_envp[++j])
					g_envp[j] = g_envp[j + 1];
				g_envp[j] = 0;
				break ;
			}
		}
	}
}
