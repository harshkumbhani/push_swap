/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:58 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/23 13:17:05 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_print(int ac, char **av)
{
	char	**tmp;
	int		i;
	int		j;
	t_stack	*stack;

	i = 0;
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (FALSE);
	while (++i < ac)
	{
		if (ft_check(av[i]) == TRUE)
		{
			tmp = ft_split(av[i], ' ');
			j = 0;
			ft_printf("\nArgument %d: \n", i);
			while (tmp[j])
			{
				ft_printf("Number %d: %d\n", j + 1, ft_atoi(tmp[j]));
				add_back(&stack->a, ft_atoi(tmp[j]));
				j++;
			}
			ft_printf("\n\n");
			ft_freearr(tmp);
		}
		else
		{
			if (stack->a)
				ft_freelist(&stack->a);
			free(stack);
			return (EXIT_FAILURE);
		}
	}  
	ft_printf_list(&stack->a);
	ft_freelist(&stack->a);
	free(stack);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	//int	i;

	//i = 0;
	//(void)argv;
	if (argc < 2)
		return (EXIT_FAILURE);
	ft_print(argc, argv);
	ft_parse(argc, argv);
	return (0);
}
