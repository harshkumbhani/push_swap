/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:58 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/21 17:47:06 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
void	ft_printf_list(t_stack *head);
//int	ft_duplicate(int i)
//{
	
//}

int	ft_print(int ac, char **av)
{
	char	**tmp;
	int		i;
	int		j;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (++i < ac)
	{
		if (ft_check(av[i]) == TRUE)
		{
			tmp = ft_split(av[i], ' ');
			j = 0;
			ft_printf("\nArgument %d: \n", i);
			while (tmp[j])
			{
				if (ft_check(tmp[j]) == FALSE)
					return (EXIT_FAILURE);
				ft_printf("Number %d: %d\n", j + 1, ft_atoi(tmp[j]));
				add_back(&stack->a, ft_atoi(tmp[j]));
				j++;
			}
			ft_printf("\n\n");
			ft_freearr(tmp);
		}
		else
			return (EXIT_FAILURE);
	}
	//ft_printf_list(stack);
	return (EXIT_SUCCESS);
}

void	ft_printf_list(t_stack *head)
{
	t_cdlist	*tmp;
	int			i;

	i = 1;
	tmp = head->a;
	while (tmp->next != head->a)
	{
		ft_printf("Node %d: %d\n", i , tmp->next);
	}
}

int	main(int argc, char **argv)
{
	//int	i;

	//i = 0;
	//(void)argv;
	if (argc < 2)
		return (EXIT_FAILURE);
	ft_print(argc, argv);
	return (0);
}
