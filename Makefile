# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgury <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 09:55:16 by sgury             #+#    #+#              #
#    Updated: 2019/07/03 11:21:40 by sgury            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sgury.filler

SRCS = filler.c \
	   ft_get_players.c \
	   ft_get_map.c \
	   ft_get_piece.c \
	   check_if_valid.c \
	   ft_score_map.c \
	   ft_place_piece.c \
	   ft_clear_data.c \
	   get_next_line/get_next_line.c 

DISPLAY = display/display_mapstruct.c \
		  display/display_piece_struct.c \
		  display/ft_put_wrd_tab_fd.c

OBJS = $(SRCS:.c=.o)

INCLUDES = filler.h

LIB_C_PATH = ./libft/

LIBFT = ./libft/libft.a

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(DISPLAY) $(LIBFT) -I $(INCLUDES)

%.o: %.c $(LIBFT)
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

$(LIBFT):
	make -C $(LIB_C_PATH)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIB_C_PATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_C_PATH)

re: fclean all

.PHONY: re fclean all clean
