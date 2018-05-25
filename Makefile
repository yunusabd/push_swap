# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 13:45:52 by yabdulha          #+#    #+#              #
#    Updated: 2018/05/25 15:05:22 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

SRCS_PATH = srcs

SRC_FILES1 = checker.c create_clist.c error_parser.c remove_clist.c swap.c \
			 rotate.c reverse_rotate.c push.c error_handler.c print_stacks.c \
			 get_input.c get_next_line.c jump_table.c check_sorted.c solver.c \
			 normalize.c list_functions.c optimizer.c options.c color.c \
			 rotate_shortcuts.c distance.c sort_back.c
SRC_FILES2 = push_swap.c create_clist.c error_parser.c remove_clist.c swap.c \
			 rotate.c reverse_rotate.c push.c error_handler.c print_stacks.c \
			 jump_table.c check_sorted.c solver.c normalize.c list_functions.c \
			 optimizer.c options.c color.c distance.c rotate_shortcuts.c \
			 sort_back.c

SRCS1 = $(addprefix $(SRCS_PATH)/,$(SRC_FILES1))
SRCS2 = $(addprefix $(SRCS_PATH)/,$(SRC_FILES2))

OBJS_PATH = objects
OBJS_PATH2 = objects2
OBJS_NAME1 = $(SRC_FILES1:.c=.o)
	OBJS_NAME2 = $(SRC_FILES2:.c=.o)
	OBJS1 = $(addprefix $(OBJS_PATH)/,$(OBJS_NAME1))
	OBJS2 = $(addprefix $(OBJS_PATH2)/,$(OBJS_NAME2))

INCLUDES_PATH = includes

INCLUDES_NAME = push_swap.h get_next_line.h libft.h
INCLUDES = $(addprefix $(INCLUDES_PATH)/,$(INCLUDE_NAME))

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIB = $(addprefix $(LIBFT_PATH)/,libft.a)

.SILENT: all, clean, fclean, re, ch, pw
	.PHONY: all, clean, fclean, re, ch, pw

ch: $(NAME1)

pw: $(NAME2)

all: ch pw

$(NAME1): libftcomp $(OBJS1) $(LIB) $(OBJS1)
	@echo "\033[31;5;mCompiling checker...\033[0m"
	gcc $(SRCS1) $(CFLAGS) -I$(INCLUDES_PATH) $(LIB) -o $(NAME1)
	@echo "\033[32;3m\nCompiling Done !\033[0m"

$(NAME2): libftcomp $(OBJS2) $(LIB) $(OBJS2)
	@echo "\033[31;5;mCompiling push_swap...\033[0m"
	gcc $(SRCS2) $(CFLAGS) -I$(INCLUDES_PATH) $(LIB) -o $(NAME2)
	@echo "\033[32;3m\nCompiling Done !\033[0m"

libftcomp:
	@echo "\033[31;5;mCompiling libft...\033[0m"
	@make all -C libft/

$(OBJS1): $(OBJS_PATH) $(SRCS1) $(INCLUDES_PATH)
	@echo "compiling source"
	gcc -c $(SRCS1) $(CFLAGS) -I$(INCLUDES_PATH) -I$(LIBFT_PATH)
	@mv $(OBJS_NAME1) $(OBJS_PATH)

$(OBJS2): $(OBJS_PATH2) $(SRCS2) $(INCLUDES_PATH)
	@echo "compiling source"
	gcc -c $(SRCS2) $(CFLAGS) -I$(INCLUDES_PATH) -I$(LIBFT_PATH)
	@mv $(OBJS_NAME2) $(OBJS_PATH2)

$(OBJS_PATH):
	@mkdir $(OBJS_PATH) 2> /dev/null || true

$(OBJS_PATH2):
	@mkdir $(OBJS_PATH2) 2> /dev/null || true

$(INCLUDES_PATH):
	@mkdir $(INCLUDES_PATH) 2> /dev/null || true
	@mv $(INCLUDE_NAME) $(INCLUDES_PATH)

clean:
	@echo "\033[32;5mCleaning..."
	@make clean -C libft/
	@rm -f $(OBJS1) $(OBJS2)
	@rmdir $(OBJS_PATH) $(OBJS_PATH2) 2> /dev/null || true
	@echo "\033[32;3mCleaning Done !\n\033[0m"

fclean: clean
	@echo "\033[32;5mFcleaning..."
	@make fclean -C libft/
	@rm -f $(NAME1) $(NAME2)
	@echo "\033[32;3mFcleaning Done !\n\033[0m"

re: fclean all

