# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 11:39:57 by hkumbhan          #+#    #+#              #
#    Updated: 2023/05/02 14:29:30 by hkumbhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set the name of the library
NAME = libftprintf.a

# Set the compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

# Set the source files for the library
SRCS = ft_printf.c ft_printnum.c ft_printstr.c

# Set the object files for mandatoru and bonus part of the libray 
OBJS = $(SRCS:%.c=%.o)

# Define the "all" rule
all: $(NAME)

# Define the rule to create the library
# Used Options
# r : Insert the objs into the archive
# c : Create the archive if it doesn't exist
# s : Create an index for the archive
# s option is an efficiency option helpful when 
# linking programs with the library
$(NAME): $(OBJS)
	@ar rcs $@ $^

# Define the rule to compile the source files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm	-f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
norm: $(SRCS)
	$(shell norminette | grep Error)
	 	
re: fclean all

# Specify that these rules do not correspond to a file name
.PHONY: all clean fclean re