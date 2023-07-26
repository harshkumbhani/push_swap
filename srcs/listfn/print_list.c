/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:24 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/26 15:00:41 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_printf_list(t_cdlist **head)
{
	t_cdlist	*tmp;
	int			i;

	i = 1;
	tmp = (*head);
	while (tmp->next != (*head))
	{
		ft_printf("Node %d: %d\n", i++, tmp->data);
		tmp = tmp->next;
	}
	ft_printf("Node %d: %d\n", i++, tmp->data);
}

void	ft_print_index(t_cdlist **stack)
{
	t_cdlist	*tmp;
	int			i;

	i = 1;
	tmp = (*stack);
	printf("Node %d: Data: %d Index: %d\n", i , tmp->data, tmp->index);
	tmp = tmp->next;
	while (tmp != (*stack))
	{
		i++;
		printf("Node %d: Data: %d Index: %d\n", i , tmp->data, tmp->index);
		tmp = tmp->next;
	}
}
