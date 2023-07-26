/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:04:27 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/26 14:59:58 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_cdlist	*new_node(int data)
{
	t_cdlist	*node;

	node = (t_cdlist *)ft_calloc(1, sizeof(t_cdlist));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node ->next = NULL;
	return (node);
}

void	prepend_node(t_cdlist **head)
{
	t_cdlist	*first;
	t_cdlist	*previous;

	first = (*head);
	previous = first->prev;
}

void	add_back(t_cdlist **head, int data)
{
	t_cdlist	*current;
	t_cdlist	*new;

	new = new_node(data);
	if (!new)
		return ;
	current = (*head);
	if (!(*head))
	{
		new->prev = new;
		new->next = new;
		*head = new;
	}
	else
	{
		while (current->next != (*head))
			current = current->next;
		new->next = (*head);
		(*head)->prev = new;
		current->next = new;
		new->prev = current;
	}
}

size_t	ft_list_len(t_cdlist **head)
{
	t_cdlist	*current;
	size_t		i;

	i = 0;
	if (!head || !(*head))
		return (i);
	current = (*head);
	current = current->next;
	i++;
	while (current != (*head))
	{
		i++;
		current = current->next;
	}
	return (i);
}
