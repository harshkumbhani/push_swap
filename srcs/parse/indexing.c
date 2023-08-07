/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:06:06 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/08/07 14:09:12 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_sort(int *arr, int len)
{
	int	i;
	int	flag;

	while (1)
	{
		flag = 0;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap(&arr[i], &arr[i + 1]);
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
			break ;
	}
}

static void	ft_put_index(t_cdlist **stack, int *arr, int len)
{
	int			i;
	t_cdlist	*current;

	current = (*stack);
	i = 0;
	if (len < 1)
	{
		current->index = i;
		return ;
	}
	while (i < len)
	{
		while (arr[i] != current->data)
			current = current->next;
		current->index = i;
		current = (*stack);
		i++;
	}
}

void	ft_indexing(t_cdlist	**stack)
{
	int			*arr;
	t_cdlist	*current;
	int			i;
	int			len;

	len = ft_list_len(stack);
	current = (*stack);
	if (!stack || !(*stack))
		return ;
	arr = (int *)ft_calloc(len, sizeof(int));
	i = -1;
	while (++i < len)
	{
		arr[i] = current->data;
		current = current->next;
	}
	ft_sort(arr, len);
	ft_put_index(stack, arr, len);
	free(arr);
}
