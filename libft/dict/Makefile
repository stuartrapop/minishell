# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 00:44:59 by pmarquis          #+#    #+#              #
#    Updated: 2022/11/19 20:24:26 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean mrproper re tests

NAME = libftdict.a

LIBFTDIR = ..
FTBTDIR = ../btree

OPT_DEBUG ?= 0
export OPT_DEBUG

CC = gcc
CFLAGS = -Wall -Wextra -Werror# -g -fsanitize=address

INC = ft_dict.h $(FTBTDIR)/ft_btree.h $(LIBFTDIR)/libft.h
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

DEFINES =

ifeq ($(OPT_DEBUG),0)
DEFINES += -DNDEBUG
OBJ := $(filter-out ft_btnode_debug.o,$(OBJ))
endif

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) -I$(LIBFTDIR) -I$(FTBTDIR) -o $@ $<

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

mrproper: fclean
	$(MAKE) -C tests mrproper

re: fclean all

tests:
	$(MAKE) -C $@

### deps
$(OBJ): $(INC)

