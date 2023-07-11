# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:34:52 by hkumbhan          #+#    #+#              #
#    Updated: 2023/04/07 11:24:57 by hkumbhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Set the name of the library
NAME = libft.a

# Set the compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Set the source files for the library
SRCS = ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_memchr.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

# Set the source files for the library
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Set the object files for mandatoru and bonus part of the libray 
OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

# Define the "all" rule
all: $(NAME)

# Define the rule to create the library
# Used Options
# r : Insert the objs intot eh archive
# c : Create the archive if it doesn't exist
# s : Create an index for the archive
# s option is an efficiency option helpful when 
# linking programs with the library
$(NAME): $(OBJS)
	ar rcs $@ $^

# Define the "bonus" rule
bonus: $(BONUS_OBJS) $(OBJS)
	ar rcs $(NAME) $^ 

# Define the rule to compile the source files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm	-f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	
norm: $(SRCS)
	$(shell norminette | grep Error)
	 	
re: fclean all

# Specify that these rules do not correspond to a file name
.PHONY: all bonus clean fclean re
