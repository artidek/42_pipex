/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:01:14 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/05 11:08:21 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_exist(char *path)
{
	if (access(path, R_OK) == 0 || access(path, X_OK) == 0)
		return (1);
	return (0);
}

int	arr_size(char **arr)
{
	int	size;

	size = 0;
	while (arr[size])
		size++;
	return (size);
}

char	**copy_arr(char **arr)
{
	int		i;
	int		size;
	char	**cp_arr;

	i = 0;
	size = arr_size(arr);
	cp_arr = malloc(sizeof(char *) * (size + 1));
	while (arr[i])
	{
		cp_arr[i] = ft_strdup(arr[i]);
		i++;
	}
	cp_arr[i] = NULL;
	return (cp_arr);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
