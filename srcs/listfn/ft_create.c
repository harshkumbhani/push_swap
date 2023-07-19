/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:04:27 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/19 10:53:16 by hkumbhan         ###   ########.fr       */
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

t_cdlist	*add_back(t_cdlist **head, int data)
{
	t_cdlist	*current;
	t_cdlist	*new;

	current = (*head);
	new = new_node(data);
	if (current == NULL)
		return (new);
	while (current->next != (*head))
		current = current->next;
	current->next = new;
	new->prev = current;
	new->next = (*head);
	(*head)->prev = new;
	return (*head);
}
