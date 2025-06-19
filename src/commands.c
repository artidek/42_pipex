/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:33:23 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/04 21:47:53 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*find_path(char *cmd, char **paths)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		temp = ft_strdup(path);
		free(path);
		path = ft_strjoin(temp, cmd);
		if (check_exist(path))
		{
			free(temp);
			return (path);
		}
		free(temp);
		free(path);
		path = NULL;
		i++;
	}
	return (path);
}

static char	*get_path(char *cmd)
{
	int		i;
	int		j;
	char	*path;
	char	**paths;
	char	**cmd_argv;

	i = 0;
	j = 0;
	paths = ft_split(PTH, ':');
	cmd_argv = split_arguments(cmd);
	path = find_path(cmd_argv[0], paths);
	while (cmd_argv[j])
		free(cmd_argv[j++]);
	free(cmd_argv);
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (path);
}

int	init_cmd(t_commands **cmd, char **argv, int argc)
{
	int		i;
	int		vector;
	char	*path;

	vector = 2;
	i = 0;
	while (i < argc - 3)
	{
		path = get_path(argv[vector]);
		if (!path)
			return (0);
		if (!*cmd)
			*cmd = create_node(ft_strdup(path), split_arguments(argv[vector]));
		else
			add_node(cmd, create_node(ft_strdup(path),
					split_arguments(argv[vector])));
		free(path);
		vector++;
		i++;
	}
	return (argc - 3);
}
