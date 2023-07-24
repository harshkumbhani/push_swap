/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:46:27 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/24 11:28:39 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_freearr(char	**arr)
{
	char	**tmp;

	tmp = arr;
	if (arr == NULL)
		return ;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
}

void	ft_freelist(t_cdlist **head)
{
	t_cdlist	*current;
	t_cdlist	*next;

	current = (*head);
	if (!current)
		return ;
	next = current->next;
	while (next != (*head))
	{
		free(current);
		current = NULL;
		current = next;
		next = current->next;
	}
	free(current);
	(*head) = NULL;
	return ;
}

void	ft_printf_list(t_cdlist **head)
{
	t_cdlist	*tmp;
	int			i;

	i = 1;
	tmp = (*head);
	while (tmp->next != (*head))
	{
		ft_printf("Node %d: %d\n", i++ , tmp->data);
		tmp = tmp->next;
	}
	ft_printf("Node %d: %d\n", i++ , tmp->data);
}

void	ft_free(char **arr, t_stack	**stack)
{
	ft_freearr(arr);
	if (stack && *stack)
	{
		if ((*stack)->a)
			ft_freelist(&(*stack)->a);
		free(*stack);
		*stack = NULL;
	}
}
