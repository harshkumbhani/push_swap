/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:33:18 by hkumbhan          #+#    #+#             */
/*   Updated: 2023/05/02 14:20:39 by hkumbhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>

#ifndef PARAM
# define PARAM "this is output for a string"
#endif

int	main()
{
	int len[2];
	printf("\n\n");
	len[0] = printf("check %d", 1234/10);
	//len[0] = printf("This is a string %s", 123);
	printf("\n\n");
	len[1] = ft_printf("check %");
	//len[1] = printf("This is a string %s", 123);
	printf("\n\nlen of printf = %d\nlen of ftprintf = %d\n",len[0],len[1]);
}

/*
0
Hello World
this is output for %%



*/