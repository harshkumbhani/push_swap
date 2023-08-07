/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:28:45 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/07 12:04:29 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **stack)
{
	swap(&(*stack)->a);
	swap(&(*stack)->b);
}

void	rr(t_stack **stack)
{
	rot(&(*stack)->a);
	rot(&(*stack)->b);
}

void	rrr(t_stack **stack)
{
	rev_rot(&(*stack)->a);
	rev_rot(&(*stack)->b);
}

int	is_sorted_bonus(t_cdlist	*stack)
{
	t_cdlist	*tmp;

	tmp = stack;
	if (stack == NULL)
		return (TRUE);
	while (tmp->next != stack)
	{
		if (tmp->index > tmp->next->index)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
