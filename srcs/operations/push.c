/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:26:32 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/25 14:33:29 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

void	pb(t_stack **stack)
{
	t_cdlist	*a;
	t_cdlist	*b;
	t_cdlist	*tmp;

	a = (*stack)->a;
	b = (*stack)->b;
	tmp = a;
	a->next->prev = a->prev;
	a->prev->next = a->next;
	(*stack)->a = a->next;
	if (b == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		(*stack)->b = tmp;
	}
	else
	{
		tmp->next = b;
		tmp->prev = b->prev;
		b->prev->next = tmp;
		b->prev = tmp;
		(*stack)->b = tmp;
	}
}

void	pb(t_stack **stack)
{
	t_cdlist	*a;
	t_cdlist	*b;
	t_cdlist	*tmp;

	a = (*stack)->a;
	b = (*stack)->b;
	tmp = a;
	a->next->prev = a->prev;
	a->prev->next = a->next;
	(*stack)->a = a->next;
	if (b == NULL)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		(*stack)->b = tmp;
	}
	else
	{
		tmp->next = b;
		tmp->prev = b->prev;
		b->prev->next = tmp;
		b->prev = tmp;
		(*stack)->b = tmp;
	}
}