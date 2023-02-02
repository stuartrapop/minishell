# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 01:33:24 by pmarquis          #+#    #+#              #
#    Updated: 2023/02/02 14:13:23 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = test_tokenize

LIBFTDIR = ../../libft

CC = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer

INC = main.h $(LIBFTDIR)/libft.h
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

INCLUDES = -I$(LIBFTDIR)/printf -I$(LIBFTDIR)

ARCHIVES = $(LIBFTDIR)/printf/libftprintf.a $(LIBFTDIR)/libft.a

.c.o:
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJ) $(ARCHIVES)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFTDIR)/libft.a:
	$(MAKE) -C $(LIBFTDIR)

$(LIBFTDIR)/printf/libftprintf.a:
	$(MAKE) -C $(LIBFTDIR)/printf

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

### deps
$(OBJ): $(INC)
