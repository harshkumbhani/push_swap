# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2023/08/07 14:27:42 by hkumbhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME 	= push_swap
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -MMD -MP -I./include -I./srcs/myLib/header -g
LIBFT_DIR = ./srcs/myLib
LIBFT_LIB = ./srcs/myLib/libft.a

TESTER_GET  =   https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER      =   ./ps_tester.pl
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

OBJDIR = ./objs

VPATH 		= .:./srcs/parse:./srcs/listfn:./srcs/operations:./srcs/sort:./srcs/bonus

SRC_PARSE 	= parse.c indexing.c utils.c

SRC_LISTFN 	= ft_create.c print_list.c list_utils.c

SRC_OPS 	= swap.c rotate.c push.c print_ops.c print_op_boosted.c

SRC_SORT 	= sort_utils.c sort_small.c sort_big.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SRCS = $(SRC_PARSE) $(SRC_LISTFN) $(SRC_OPS) $(SRC_SORT) push_swap.c
OBJS = $(addprefix $(OBJDIR)/, ${SRCS:%.c=%.o})

BONUS_SRC = $(SRC_PARSE) $(SRC_LISTFN) $(SRC_OPS) checker.c bonus_utils.c
BONUS_OBJS = $(addprefix $(OBJDIR)/, ${BONUS_SRC:%.c=%.o})
################################################################################
#                                 Makefile logic                               #
################################################################################

COM_COLOR   = \033[0;34m # Blue
OBJ_COLOR   = \033[0;36m # Cyan
ERROR_COLOR = \033[0;31m # Red
WARN_COLOR  = \033[0;33m # Yellow
OK_COLOR    = \033[0;32m # Green
NO_COLOR    = \033[m 

COM_STRING   = "Compiling"

################################################################################
#                                 Makefile rules                             #
################################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR)$(OBJS) $(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $@
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o program 

$(LIBFT_LIB):
	@make re -C $(LIBFT_DIR) > make_output.txt 2>&1; \
	if [ $$? -eq 0 ]; then \
		echo "$(OK_COLOR)LIBFT.A compilation successful.$(NO_COLOR)"; \
	else \
		echo "$(ERROR_COLOR)LIBFT.A compilation failed.$(NO_COLOR) Check make_output.txt for details."; \
		exit 1; \
	fi

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

bonus: checker

checker: $(BONUS_OBJS) $(LIBFT_LIB)
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR)$(OBJS) $(NO_COLOR)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) -o $@

$(TESTER):
	curl $(TESTER_GET) -o $(TESTER)
3: $(NAME) $(TESTER)
	perl $(TESTER) 3 100
5: $(NAME) $(TESTER)
	perl $(TESTER) 5 100
100: $(NAME) $(TESTER)
	perl $(TESTER) 100 100
500: $(NAME) $(TESTER)
	perl $(TESTER) 500 100

clean:
	@echo
	@printf "%b" "$(COM_COLOR)Cleaning objects and dependency files...$(NO_COLOR)"
	@make clean -C $(LIBFT_DIR)
	@rm -rf objs program make_output.txt
	@echo

fclean: clean
	@printf "%b" "$(COM_COLOR)Cleaning libft library...$(NO_COLOR)"
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) checker
	@echo

norm: $(SRCS)
	$(shell norminette | grep Error)

re: fclean all

.PHONY: all clean fclean re $(LIBFT) bonus