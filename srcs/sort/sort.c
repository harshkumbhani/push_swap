/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:49:44 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/27 12:36:21 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/sort.h"

static void	sort_three(t_stack **stack)
{
	t_cdlist	*top;

	top = (*stack)->a;
	if (is_sorted((*stack)->a) == TRUE)
		return ;
	while (is_sorted((*stack)->a) != TRUE)
	{
		if (top->index > top->next->index
			&& top->index > top->next->next->index)
			do_operation(stack, RA);
		if (top->next->index > top->index
			&& top->next->index > top->next->next->index)
			do_operation(stack, RRA);
		if (top->index > top->next->index)
			do_operation(stack, SA);
	}
}

void	sort(t_stack **stack)
{
	size_t	len;

	len = ft_list_len(&(*stack)->a);
	if (len == 1)
		return ;
	if (len == 2)
	{
		if (is_sorted((*stack)->a) == FALSE)
			do_operation(stack, SA);
	}
	if (len == 3)
		sort_three(stack);
	return ;
}
