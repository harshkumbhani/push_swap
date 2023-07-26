/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:33:02 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/26 10:53:30 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

void	rot(t_cdlist **stack)
{
	if (stack == NULL || (*stack) == NULL)
		return ;
	(*stack) = (*stack)->next;
}

void	rot_both(t_stack **stack)
{
	if (stack == NULL)
		return ;
	rot(&(*stack)->a);
	rot(&(*stack)->b);
}

void	rev_rot(t_cdlist **stack)
{
	if (stack == NULL || (*stack) == NULL)
		return ;
	(*stack) = (*stack)->prev;
}

void	rev_rot_both(t_stack **stack)
{
	if (stack == NULL)
		return ;
	rev_rot(&(*stack)->a);
	rev_rot(&(*stack)->b);
}
