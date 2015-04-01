# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laime <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 17:48:46 by laime             #+#    #+#              #
#    Updated: 2015/02/11 17:48:48 by laime            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STATIC_EXE	= push_swap
DEBUG_EXE	= push_swap_debug

SRC		=	main.c			\
			dlist.c			\
			command.c		\
			resolve.c		\
			error.c

HEAD_DIR	= includes
SRC_DIR		= src
DEBUG_DIR	= debug
STATIC_DIR	= static
C_HEAD_DIR	= debug

LIBFT_STATIC= libft/libft.a
LIBFT_HEAD	= libft/

STATIC_OBJ	= $(patsubst %.c,$(STATIC_DIR)/%.o,$(SRC))
DEBUG_OBJ	= $(patsubst %.c,$(DEBUG_DIR)/%.o,$(SRC))

CC			= gcc
NORMINETTE	= norminette
OPTI		= -O3
FLAGS		= -Wall -Wextra -Werror


$(shell mkdir -p $(STATIC_DIR) $(DEBUG_DIR))

all: $(STATIC_EXE)
	@echo "Compilation terminee. (realease)"

debug: $(DEBUG_EXE)
	@echo "Compilation terminee. (debug)"

$(DEBUG_EXE): $(DEBUG_OBJ) $(LIBFT_STATIC)
	$(CC) -O0 -I $(HEAD_DIR) -I $(LIBFT_HEAD) -o $(DEBUG_EXE) $(DEBUG_OBJ) $(LIBFT_DEBUG) $(FLAGS) -g

$(STATIC_EXE): $(STATIC_OBJ) $(LIBFT_STATIC)
	$(CC) $(OPTI) -I $(HEAD_DIR) -I $(LIBFT_HEAD) -o $@ $(STATIC_OBJ) $(LIBFT_STATIC) $(FLAGS)

$(STATIC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(OPTI) -I $(HEAD_DIR) -I $(LIBFT_HEAD) -o $@ -c $< $(FLAGS)

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -O0 -I $(HEAD_DIR) -I $(LIBFT_HEAD) -o $@ -c $< $(FLAGS) -g

$(LIBFT_STATIC):
	make -C libft/ libft.a

.PHONY: clean fclean re debug norme

clean:
	rm -f $(STATIC_OBJ) $(DEBUG_OBJ)
	make -C libft clean

fclean: clean
	rm -f $(STATIC_EXE) $(DEBUG_EXE)
	make -C libft fclean

norme:
	$(NORMINETTE) $(SRC_DIR)/ $(HEAD_DIR)/

re: fclean
	make
