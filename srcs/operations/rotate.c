/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:33:02 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/26 08:12:14 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

void	rotate(t_cdlist **stack)
{
	if (stack == NULL || (*stack) == NULL)
		return ;
	(*stack) = (*stack)->next;
}

void	rotate_both(t_stack **stack)
{
	if (stack == NULL)
		return ;
	rotate(&(*stack)->a);
	rotate(&(*stack)->b);
}

void	rev_rotate(t_cdlist **stack)
{
	if (stack == NULL || (*stack) == NULL)
		return ;
	(*stack) = (*stack)->prev;
}

void	rrr(t_stack **stack)
{
	if (stack == NULL)
		return ;
	rev_rotate(&(*stack)->a);
	rev_rotate(&(*stack)->b);
}
