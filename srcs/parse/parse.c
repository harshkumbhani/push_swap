/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:19:12 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/27 16:57:56 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	ft_isvalidarg(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (FALSE);
	while (str[i])
	{
		while (str[i] != '\0' && ft_isspace(str[i]) == TRUE)
			i++;
		if (str[i] == '\0')
			return (TRUE);
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] != '\0' && ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	ft_duplicate(t_cdlist **stack, int num)
{
	t_cdlist	*current;

	if (!stack || !(*stack))
		return (TRUE);
	current = (*stack);
	if (current->data == num)
		return (FALSE);
	current = current->next;
	while (current != (*stack))
	{
		if (num == current->data)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

static int	ft_check(const char *str, t_cdlist **stack)
{
	(void)stack;
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (FALSE);
	if (ft_duplicate(stack, ft_atoi(str)) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	ft_process_arg(char *arg, t_stack **stack)
{
	char	**arr;
	int		j;

	arr = ft_split(arg, ' ');
	j = 0;
	if (arr[j] == NULL)
	{
		ft_freearr(arr);
		return (EXIT_SUCCESS);
	}
	while (arr[j])
	{
		if (ft_check(arr[j], &(*stack)->a) == TRUE)
			add_back(&(*stack)->a, ft_atoi(arr[j++]));
		else
		{
			ft_free(arr, stack);
			return (EXIT_FAILURE);
		}
	}
	ft_freearr(arr);
	return (EXIT_SUCCESS);
}

int	ft_parse(int ac, char **av, t_stack **stack)
{
	int	i;
	int	exit_status;

	i = 0;
	exit_status = EXIT_FAILURE;
	while (++i < ac)
	{
		if (ft_isvalidarg(av[i]) != TRUE)
			break ;
		if (ft_process_arg(av[i], stack) != EXIT_SUCCESS)
			break ;
	}
	if (i == ac)
	{
		ft_indexing(&(*stack)->a);
		exit_status = EXIT_SUCCESS;
	}
	if (exit_status == EXIT_FAILURE)
		ft_free(NULL, stack);
	return (exit_status);
}
//static int ft_parse_and_validate_args(int ac, char **av, t_stack **stack)
//{
//	int		i;

//	i = 0;
//	while (++i < ac)
//	{
//		if (ft_isvalidarg(av[i]) != TRUE)
//			return (EXIT_FAILURE);
//		if (ft_process_arg(av[i], stack) != EXIT_SUCCESS)
//			return (EXIT_FAILURE);
//	}
//	return (EXIT_SUCCESS);
//}

//int	ft_parse(int ac, char **av, t_stack **stack)
//{
//	int exit_status;

//	exit_status = ft_parse_and_validate_args(ac, av, stack);
//	if (exit_status == EXIT_SUCCESS)
//	{
//		ft_printf_list(&(*stack)->a);
//		ft_freelist(&(*stack)->a);
//	}
//	else
//	{
//		if ((*stack)->a)
//			ft_freelist(&(*stack)->a);
//	}
//	free(*stack);
//	*stack = NULL;
//	exit(exit_status);
//}

// PSEUDO CODE

//int	ft_parse(int ac, char **av, t_stack **stack)
//{
//	char	**arr;
//	int		i;
//	int		j;

//	i = 0;
//	while (++i < ac)
//	{
//		if (ft_isvalidarg(av[i]) == TRUE)
//		{
//			arr = ft_split(av[i], ' ');
//			j = 0;
//			if (arr[j] == NULL)
//			{
//				ft_freearr(arr);
//				continue;
//			}
//			while (arr[j])
//			{
//				if (ft_check(arr[j], &(*stack)->a) == TRUE)
//					add_back(&(*stack)->a, ft_atoi(arr[j++]));
//				else
//				{
//					if (*stack == NULL)
//						return (EXIT_FAILURE);
//					ft_free(arr, stack);
//					return (EXIT_FAILURE);
//				}
//			}
//			ft_freearr(arr);
//		}
//		else
//		{
//			if ((*stack)->a)
//				ft_freelist(&(*stack)->a);
//			free(*stack);
//			*stack = NULL;
//			return (EXIT_FAILURE);
//		}
//	}
//	ft_printf_list(&(*stack)->a);
//	ft_freelist(&(*stack)->a);
//	free(*stack);
//	return (EXIT_SUCCESS);
//}