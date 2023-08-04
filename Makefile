# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2023/08/04 13:51:53 by hkumbhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME 	= push_swap
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -MMD -MP -I./include -I./srcs/myLib/header -g
HEADERS = -I./include -I./srcs/myLib/header
DEPS = ./header/push_swap_h
LIBFT_DIR = ./srcs/myLib
LIBFT = ./srcs/myLib/libft.a
AUTHOR	= hkumbhan
DATE	= 10.07.2023
NOVISU 	= 0

TESTER_GET  =   https://raw.githubusercontent.com/lorenuars19/push_swap_tester/main/push_swap_tester.pl
TESTER      =   ./ps_tester.pl
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

OBJDIR = objs
FILE_EXTENSION = .c

VPATH 		= .:./srcs/parse:./srcs/listfn:./srcs/operations:./srcs/sort:./srcs/bonus

SRC_PARSE 	= parse.c indexing.c utils.c

SRC_LISTFN 	= ft_create.c print_list.c list_utils.c

SRC_OPS 	= swap.c rotate.c push.c print_ops.c print_op_boosted.c

SRC_SORT 	= sort_utils.c sort_small.c sort_big.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SRCS = $(SRC_PARSE) $(SRC_LISTFN) $(SRC_OPS) $(SRC_SORT) push_swap.c
OBJS = $(addprefix objs/, ${SRCS:%$(FILE_EXTENSION)=%.o})

BONUS_SRC = $(SRC_PARSE) $(SRC_LISTFN) $(SRC_OPS) checker.c bonus_utils.c
BONUS_OBJS = $(addprefix objs/, ${BONUS_SRC:%$(FILE_EXTENSION)=%.o})
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

RUN_CMD = $(1) 2> $@.log; \
		RESULT=$$?

define run_and_test
	printf "%b%-46b" "$(COM_COLOR)$(COM_STRING) " "$(OBJ_COLOR)$(@F)$(NO_COLOR)"; \
	$(RUN_CMD); \
	if [ $$RESULT -ne 0 ]; then \
		printf "%b\n" "$(ERROR_COLOR)[✖]$(NO_COLOR)"; \
		if [ $(NOVISU) -eq 0 ]; then \
			echo; \
		fi; \
	elif [ -s $@.log ]; then \
		printf "%b\n" "$(WARN_COLOR)[⚠]$(NO_COLOR)"; \
	else  \
		printf "%b\r" "$(OK_COLOR)[✓]$(NO_COLOR)"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

################################################################################
#                                 Makefile rules                             #
################################################################################

all: header $(NAME) bonus

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "       ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo

	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
	@printf "%b" "$(OBJ_COLOR)Author:$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date:  $(WARN_COLOR)$(DATE)\n"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n"
	@printf "%b" "$(OBJ_COLOR)Flags: $(WARN_COLOR)$(CFLAGS)\n"
	@echo

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR)$(OBJS) $(NO_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) -lft -L./srcs/myLib -o $@
	@$(CC) $(CFLAGS) $(OBJS) -lft -L./srcs/myLib -o program

$(LIBFT):
	@make re -C $(LIBFT_DIR) > make_output.txt 2>&1; \
	if [ $$? -eq 0 ]; then \
		echo "$(OK_COLOR)LIBFT.A compilation successful.$(NO_COLOR)"; \
	else \
		echo "$(ERROR_COLOR)LIBFT.A compilation failed.$(NO_COLOR) Check make_output.txt for details."; \
		exit 1; \
	fi

objs/%.o: %.c
	@mkdir -p $(dir $@)
	@$(call run_and_test,$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ )
#	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

bonus: $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -lft -L./srcs/myLib -o checker

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

clean: header
	@echo
	@printf "%b" "$(COM_COLOR)Cleaning objects and dependency files...$(NO_COLOR)"
	@rm -rf objs
	@printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)"
	@echo

fclean: header clean
	@printf "%b" "$(COM_COLOR)Cleaning library...$(NO_COLOR)"
	@rm -f $(NAME)
	@printf "%b\n" "$(OK_COLOR)[✓]$(NO_COLOR)"
	@echo

norm: $(SRCS)
	$(shell norminette | grep Error)

re: fclean all


.PHONY: all clean fclean re header $(LIBFT)