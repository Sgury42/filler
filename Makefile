# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgury <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 09:55:16 by sgury             #+#    #+#              #
#    Updated: 2019/06/29 10:36:05 by sgury            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sgury.filler

SRCS = filler.c \
	   ft_get_players.c \
	   ft_get_map.c \
	   ft_get_piece.c \
	   ft_score_map.c \
	   ft_place_piece.c \
	   ft_clear_data.c \
	   get_next_line/get_next_line.c 

DISPLAY = display/display_mapstruct.c \
		  display/display_piece_struct.c \
		  display/ft_put_wrd_tab_fd.c

OBJS = $(SRCS:.c=.o)

INCLUDES = filler.h

LIBFT = ./libft/libft.a

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(DISPLAY) $(LIBFT)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(LIBFT):
	make -C libft/

clean:
	rm -rf $(OBJS)
#	clean -C libft/

fclean: clean
	rm -rf $(NAME)
#	fclean -C libft/

re: fclean all

.PHONY: re fclean all clean
