/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:57:52 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/26 10:52:39 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

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
	second = first->next;
	first->next = second->next;
	first->next->prev = first;
	first->prev = second;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	(*stack) = second;
}

void	swap_both(t_stack **stack)
{
	if (stack == NULL)
		return ;
	swap(&(*stack)->a);
	swap(&(*stack)->b);
}
