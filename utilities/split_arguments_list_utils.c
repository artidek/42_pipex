/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arguments_list_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aobshatk <aobshatk@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:09:57 by aobshatk          #+#    #+#             */
/*   Updated: 2025/03/04 16:38:11 by aobshatk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	del_a(char *argument)
{
	if (argument)
		free(argument);
}

t_arguments	*create_node_a(char *argument)
{
	t_arguments	*new_node;

	new_node = malloc(sizeof(t_arguments));
	if (!new_node)
		return (NULL);
	new_node->argument = argument;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_a(t_arguments **lst, t_arguments *new)
{
	t_arguments	*temp;

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

void	clear_list_a(t_arguments **lst, void (*del_a)(char *))
{
	t_arguments	*temp;

	if (!lst || !del_a)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		delete_node_a(*lst, del_a);
		*lst = temp;
	}
}

void	delete_node_a(t_arguments *lst, void (*del_a)(char *))
{
	if (!lst || !del_a)
		return ;
	del_a(lst->argument);
	free(lst);
}
