/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:07:34 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/25 08:56:00 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

# define FALSE 0
# define TRUE  1

// Libft library headers

# include "../srcs/myLib/header/library.h"

// Struct for circular doubly linked list

typedef	struct s_cdlist
{
	int				data;
	int				index;
	struct s_cdlist	*prev;
	struct s_cdlist	*next;
}	t_cdlist;

typedef	struct s_stack
{
	t_cdlist	*a;
	t_cdlist	*b;
}	t_stack;

# define ALLOC_FAIL NULL

// Functions from the LISTFN folder

t_cdlist	*new_node(int data);
void		add_back(t_cdlist **head, int data);
void		ft_printf_list(t_cdlist **head);
size_t		ft_list_len(t_cdlist **head);

// List from the PARSE folder

void		ft_freearr(char	**arr);
void		ft_freelist(t_cdlist **head);
int			ft_parse(int ac, char **av, t_stack **stack);
void		ft_free(char **arr, t_stack	**stack);
void		ft_indexing(t_cdlist	**stack);

#endif
