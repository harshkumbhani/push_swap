/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:26:32 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/04 10:30:20 by hkumbhan         ###   ########.fr       */
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


// Pseudo code for pushing nodes

//void	pb(t_stack **stack)
//{
//	t_cdlist	*node_to_push;

//	if ((*stack)->a == NULL)
//		return ;
//	node_to_push = (*stack)->a;
//	(*stack)->a = (*stack)->a->next;
//	(*stack)->a->prev = node_to_push->prev;
//	node_to_push->prev->next = (*stack)->a;
//	if ((*stack)->b == NULL)
//	{
//		node_to_push->next = node_to_push;
//		node_to_push->prev = node_to_push;
//	}
//	else
//	{
//		node_to_push->next = (*stack)->b;
//		node_to_push->prev = (*stack)->b->prev;
//		(*stack)->b->prev->next = node_to_push;
//		(*stack)->b->prev = node_to_push;
//	}
//	(*stack)->b = node_to_push;
//}

//void	pa(t_stack **stack)
//{
//	t_cdlist	*node_to_push;

//	if ((*stack)->b == NULL)
//		return ;
//	node_to_push = (*stack)->b;
//	(*stack)->b = (*stack)->b->next;
//	(*stack)->b->prev = node_to_push->prev;
//	node_to_push->prev->next = (*stack)->b;
//	if ((*stack)->a == NULL)
//	{
//		node_to_push->next = node_to_push;
//		node_to_push->prev = node_to_push;
//	}
//	else
//	{
//		node_to_push->next = (*stack)->a;
//		node_to_push->prev = (*stack)->a->prev;
//		(*stack)->a->prev->next = node_to_push;
//		(*stack)->a->prev = node_to_push;
//	}
//	(*stack)->a = node_to_push;
//}
