/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:57:52 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/04 10:30:28 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_cdlist **stack)
{
	t_cdlist	*first;
	t_cdlist	*second;
	int			list_len;

	if (stack == NULL || (*stack) == NULL)
		return ;
	first = (*stack);
	list_len = ft_list_len(&first);
	if (list_len < 2)
		return ;
	if (list_len == 2)
	{
		rot(stack);
		return ;
	}
	second = first->next;
	first->next = second->next;
	first->prev->next = second;
	first->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	(*stack) = second;
}

void	swap_both(t_stack **stack)
{
	if (stack == NULL)
		return ;
	swap(&(*stack)->a);
	swap(&(*stack)->b);
}
