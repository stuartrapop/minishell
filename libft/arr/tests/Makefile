# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 15:45:23 by pmarquis          #+#    #+#              #
#    Updated: 2022/12/23 15:57:27 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mrproper

CC = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address

INC = ../ft_arr.h ../../libft.h
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

DEFINES =

INCLUDES = -I.. -I../..

ARCHIVES = ../libftarr.a ../../libft.a

.DEFAULT_GOAL = test

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

test: $(OBJ) $(ARCHIVES)
	$(CC) $(CFLAGS) $^ -o $@

../libftarr.a:
	$(MAKE) -C ..

../../libft.a:
	$(MAKE) -C ../..

all: test

clean:
	rm -f *.o

fclean: clean
	rm -f test

re: fclean all

mrproper: fclean

### deps
$(OBJ): $(INC)
