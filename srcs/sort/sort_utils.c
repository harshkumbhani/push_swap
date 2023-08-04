/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:11:46 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/04 11:06:31 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_cdlist	*stack)
{
	t_cdlist	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->index > tmp->next->index)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	case_rarb(t_stack **stack, int index)
{
	int	i;

	i = pos_in_b((*stack)->b, index);
	if (i < return_pos((*stack)->a, index))
		i = return_pos((*stack)->a, index);
	return (i);
}

int	case_rrarrb(t_stack **stack, int index)
{
	int	i;

	i = ft_list_len(&(*stack)->b) - pos_in_b((*stack)->b, index);
	if (i < ft_list_len(&(*stack)->a) - return_pos((*stack)->a, index))
		i = ft_list_len(&(*stack)->a) - return_pos((*stack)->a, index);
	return (i);
}

int	case_rarrb(t_stack **stack, int index)
{
	int	i;

	i = ft_list_len(&(*stack)->b) - pos_in_b((*stack)->b, index);
	i = return_pos((*stack)->a, index) + i;
	return (i);
}

int	case_rrarb(t_stack **stack, int index)
{
	int	i;

	i = pos_in_b((*stack)->b, index);
	i = ft_list_len(&(*stack)->a) - return_pos((*stack)->a, index) + i;
	return (i);
}
