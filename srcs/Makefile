# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkumbhan <hkumbhan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:13:53 by hkumbhan          #+#    #+#              #
#    Updated: 2023/07/20 11:46:45 by hkumbhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME 	= push_swap
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -MMD -MP -I./include -I./srcs/myLib/header
HEADERS = -I./include -I./srcs/myLib/header
DEPS = ./header/push_swap_h
LIBFT_DIR = ./myLib
LIBFT = ./myLib/libft.a
AUTHOR	= hkumbhan
DATE	= 10.07.2023
HASH 	=
NOVISU 	= 0

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

OBJDIR = objs
FILE_EXTENSION = .c

VPATH = .:./parse:./listfn
SRC_PARSE = parse.c
SRC_LISTFN = ft_create.c

################################################################################
#                                  Makefile  objs                              #
################################################################################

SRCS = $(SRC_PARSE) $(SRC_LISTFN) push_swap.c utils.c 
OBJS = $(addprefix objs/, ${SRCS:%$(FILE_EXTENSION)=%.o})

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

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

RUN_CMD = $(1) 2> $@.log; \
		RESULT=$$?

ifeq ($(shell git rev-parse HEAD &>/dev/null; echo $$?),0)
	AUTHOR	:= $(shell git log --format='%aN' | sort -u | awk '{printf "%s, ", $$0}' | rev | cut -c 3- | rev)
	DATE	:= $(shell git log -1 --date=format:"%Y/%m/%d %T" --format="%ad")
	HASH	:= $(shell git rev-parse --short HEAD)
endif

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

all: header $(NAME)

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "       ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo

#ifneq ($(HASH),)
#	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
#else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
#endif
	@printf "%b" "$(OBJ_COLOR)Author:$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date:  $(WARN_COLOR)$(DATE)\n"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n"
	@printf "%b" "$(OBJ_COLOR)Flags: $(WARN_COLOR)$(CFLAGS)\n"
	@echo

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(COM_COLOR)$(COM_STRING) $@ $(OBJ_COLOR)$(OBJS) $(NO_COLOR)"
	$(CC) $(CFLAGS) $(OBJS) -lft -L./myLib -o $@

objs/%.o: %.c
	@mkdir -p $(dir $@)
	@$(call run_and_test,$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ )

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

.PHONY: all clean fclean re header