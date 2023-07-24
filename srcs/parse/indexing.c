/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:06:06 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/24 16:18:33 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_swap_index(int *a, int *b)

void	ft_indexing(t_cdlist	**stack)
{
	int			arr[ft_list_len(stack)];
	t_cdlist	*current;
	int			i;

	i = -1;
	current = (*stack);
	if (!stack || !(*stack))
		return ;
	while (++i < ft_list_len(stack))
	{
		arr[i] = current->data;
		current = current->next;
	}
}
