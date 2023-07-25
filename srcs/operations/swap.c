/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:57:52 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/25 10:37:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

void	sa(t_stack **stack)
{
	t_cdlist	*first;
	t_cdlist	*second;

	first = ((*stack)->a);
	second = first->next;
	first->next = second->next;
	first->next->prev = first;
	first->prev = second;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	(*stack)->a = second;
	ft_printf("sa\n");
}

void	sb(t_stack **stack)
{
	t_cdlist	*first;
	t_cdlist	*second;

	first = ((*stack)->b);
	second = first->next;
	first->next = second->next;
	first->next->prev = first;
	first->prev = second;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	(*stack)->b = second;
	ft_printf("sb\n");
}

void	ss(t_stack **stack)
{
	sa(stack);
	sb(stack);
	ft_printf("ss\n");
}

void	rra(t_stack **stack)
{
	(*stack)->a = (*stack)->a->prev;
	ft_printf("rra\n");
}

void	rrb(t_stack **stack)
{
	(*stack)->b = (*stack)->b->prev;
	ft_printf("rrb\n");
}