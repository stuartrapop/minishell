# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 02:32:53 by pmarquis          #+#    #+#              #
#    Updated: 2022/12/17 22:35:26 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean mrproper re ../libft.a

# OPTIONS
OPT_MEMLIST ?= 1
###

NAME = test

CC = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address

INC = $(wildcard *.h)
INC +=$(wildcard ../*.h)
SRC = $(wildcard *.c)
SRC :=$(filter-out ft_utf8_check_test.c ft_utf8_len_test.c,$(SRC))
OBJ = $(patsubst %.c,%.o,$(SRC))

DEFINES :=

ifeq ($(OPT_MEMLIST),0)
DEFINES += -DNMEMLIST
endif

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) -I.. -o $@ $<

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJ) ../libft.a
	$(CC) $(CFLAGS) $^ -o $@

../libft.a:
	$(MAKE) -C ..

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

mrproper: fclean

re: fclean all

###
$(OBJ): $(INC)

