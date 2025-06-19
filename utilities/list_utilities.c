/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:01:16 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/04 21:48:58 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	del(char *path, char **argv)
{
	int	i;

	i = 0;
	if (path)
		free(path);
	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

t_commands	*create_node(char *path, char **argv)
{
	t_commands	*new_node;

	new_node = malloc(sizeof(t_commands));
	if (!new_node)
		return (NULL);
	new_node->path = path;
	new_node->argv = argv;
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_commands **lst, t_commands *new)
{
	t_commands	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	clear_list(t_commands **lst, void (*del)(char *, char **))
{
	t_commands	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		delete_node(*lst, del);
		*lst = temp;
	}
}

void	delete_node(t_commands *lst, void (*del)(char *, char **))
{
	if (!lst || !del)
		return ;
	del(lst->path, lst->argv);
	free(lst);
}
