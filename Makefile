# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabdulha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 13:45:52 by yabdulha          #+#    #+#              #
#    Updated: 2018/05/27 21:21:59 by yabdulha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(NAME1) $(NAME2)

NAME1 = checker
NAME2 = push_swap

SRCS_PATH = srcs

SRC_FILES1 = checker.c create_clist.c error_parser.c remove_clist.c swap.c \
			 rotate.c reverse_rotate.c push.c error_handler.c \
			 get_input.c get_next_line.c jump_table.c check_sorted.c solver.c \
			 normalize.c list_functions.c optimizer.c options.c color.c \
			 rotate_shortcuts.c distance.c sort_back.c visualizer.c
SRC_FILES2 = push_swap.c create_clist.c error_parser.c remove_clist.c swap.c \
			 rotate.c reverse_rotate.c push.c error_handler.c \
			 jump_table.c check_sorted.c solver.c normalize.c list_functions.c \
			 optimizer.c options.c color.c distance.c rotate_shortcuts.c \
			 sort_back.c

SRCS1 = $(addprefix $(SRCS_PATH)/,$(SRC_FILES1))
SRCS2 = $(addprefix $(SRCS_PATH)/,$(SRC_FILES2))

OBJS_PATH1 = objects/
OBJS_PATH2 = objects2/
OBJS_NAME1 = $(SRC_FILES1:.c=.o)
OBJS_NAME2 = $(SRC_FILES2:.c=.o)
OBJS1 = $(addprefix $(OBJS_PATH1),$(OBJS_NAME1))
OBJS2 = $(addprefix $(OBJS_PATH2),$(OBJS_NAME2))

INCLUDES_PATH = includes

INCLUDES_NAME = push_swap.h get_next_line.h libft.h
INCLUDES = $(addprefix $(INCLUDES_PATH)/,$(INCLUDE_NAME))

CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
LIB = $(addprefix $(LIBFT_PATH)/,libft.a)

FT_PRINTF = libft/ft_printf/libftprintf.a

PRINTF_PATH = libft/ft_printf/
PRINTF_NAME = libftprintf.a
PRINTF_A = $(addprefix $(PRINTF_PATH),$(PRINTF_NAME))
PRINTF_H = $(addprefix $(PRINTF_PATH),includes/ft_printf.h)

.SILENT: all, clean, fclean, re
.PHONY: all, clean, fclean, re

all: $(NAME)

$(FT_PRINTF):
	@make -C libft/ft_printf/ all

$(LIB):
	@make -C libft/ all

$(NAME1): $(OBJS1)
	@gcc $(CFLAGS) -o $(NAME1) $(OBJS1) libft/libft.a $(FT_PRINTF)
	@echo '\033[0;32m'***checker Compiled***'\033[0m'

$(NAME2): $(OBJS2)
	@gcc $(FLAGS) -o $(NAME2) $(OBJS2) libft/libft.a $(FT_PRINTF)
	@echo '\033[0;32m'***push_swap Compiled***'\033[0m'

$(OBJS1): $(SRCS1) $(FT_PRINTF) $(LIB)
	@echo '\033[0;34m'***Compiling Push_Swap***'\033[0m'
	@gcc -I $(INCLUDES_PATH) $(CFLAGS) -c $(SRCS1)
	@mkdir $(OBJS_PATH1) 2> /dev/null || true
	@mv $(OBJS_NAME1) $(OBJS_PATH1)

$(OBJS2): $(SRCS2) $(FT_PRINTF) $(LIB)
	@echo '\033[0;34m'***Compiling Push_Swap***'\033[0m'
	@gcc -I $(INCLUDES_PATH) $(CFLAGS) -c $(SRCS2)
	@mkdir $(OBJS_PATH2) 2> /dev/null || true
	@mv $(OBJS_NAME2) $(OBJS_PATH2)

clean:
	@/bin/rm -rf $(OBJS_PATH1) $(OBJS_PATH2)
	@echo '\033[0;31m'***Deleted Push_Swap Objects***'\033[0m'
	@make -C libft/ clean
	@make -C libft/ft_printf/ clean

fclean: clean
	@/bin/rm -f $(NAME1) $(NAME2)
	@echo '\033[0;31m'***Deleted Push_Swap Objects and Library***'\033[0m'
	@make -C libft/ fclean
	@make -C libft/ft_printf/ fclean

re: fclean all

