/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:07:34 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/07/18 09:55:39 by hkumbhan         ###   ########.fr       */
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

// Libft libraray headers

# include "../myLib/header/ft_printf.h"
# include "../myLib/header/get_next_line.h"
# include "../myLib/header/libft.h"

// Struct for circular doubly linked list

typedef	struct s_cdlist
{
	int	index;
	int	data;
	struct s_cdlist	*prev;
	struct s_cdlist	*next;
}	t_cdlist;


#endif
