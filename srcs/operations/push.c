/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:26:32 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/07 14:08:31 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_update_node(t_cdlist	*node_to_push, t_cdlist *dst)
{
	node_to_push->next = dst;
	node_to_push->prev = dst->prev;
	dst->prev->next = node_to_push;
	dst->prev = node_to_push;
}

static void	push(t_cdlist **src, t_cdlist **dst)
{
	t_cdlist	*node_to_push;

	if ((*src) == NULL)
		return ;
	node_to_push = (*src);
	if (node_to_push->next == node_to_push)
		(*src) = NULL;
	else
	{
		(*src) = (*src)->next;
		(*src)->prev = node_to_push->prev;
		node_to_push->prev->next = (*src);
	}
	if ((*dst) == NULL)
	{
		node_to_push->next = node_to_push;
		node_to_push->prev = node_to_push;
	}
	else
		ft_update_node(node_to_push, *dst);
	(*dst) = node_to_push;
}

void	pa(t_stack	**stack)
{
	push(&(*stack)->b, &(*stack)->a);
}

void	pb(t_stack	**stack)
{
	push(&(*stack)->a, &(*stack)->b);
}
