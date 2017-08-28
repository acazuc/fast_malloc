# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2017/08/28 20:39:15 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HOSTTYPE ?= $(shell uname -m)_$(shell uname -s)

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O2 -march=native -flto=8

INCLUDES_PATH = include/

SRCS_PATH = src/

SRCS_NAME = alloc_page.c \
			get_block_type.c \
			get_existing_block.c \
			get_page_size.c \
			malloc.c \
			get_block_size.c \
			push_new_page.c \
			create_new_block.c \
			free.c \
			show_alloc_mem.c \
			show_alloc_mem_2.c \
			remove_page.c \
			realloc.c \
			check_free_pages.c \
			getpagesize_mult.c \
			calloc.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft -lpthread

all: odir $(NAME)

test:
	$(CC) $(CFLAGS) $(SRCS_PATH)main.c $(SRCS_PATH)main_2.c -o test -I includes -L libft -lft -L . -lft_malloc_$(HOSTTYPE)

$(NAME): $(OBJS)
	@make -C libft
	@echo " - Making $(NAME)"
	@$(CC) -shared $(CFLAGS) -o $(NAME) $^ $(LIBRARY)
	@ln -sf $(NAME) libft_malloc.so

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -fPIC -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C libft clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)
	@rm -f libft_malloc.so

re: fclean all

.PHONY: clean fclean re odir
