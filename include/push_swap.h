/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:07:34 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/18 12:00:01 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define FALSE 0
# define TRUE  1

// Libft library headers

# include "myLib/header/library.h"

// Struct for circular doubly linked list

typedef	struct s_cdlist
{
	int				index;
	int				data;
	struct s_cdlist	*prev;
	struct s_cdlist	*next;
}	t_cdlist;

typedef	struct s_stack
{
	t_cdlist	*a;
	t_cdlist	*b;
} stack;

#endif
