/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:33:02 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/25 10:38:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

void	ra(t_stack **stack)
{
	(*stack)->a = (*stack)->a->next;
	ft_printf("ra\n");
}

void	rb(t_stack **stack)
{
	(*stack)->b = (*stack)->b->next;
	ft_printf("rb\n");
}

void	rr(t_stack **stack)
{
	ra(stack);
	rb(stack);
	ft_printf("rr\n");
}

void	rrr(t_stack **stack)
{
	rra(stack);
	rrb(stack);
	ft_printf("rrr\n");
}