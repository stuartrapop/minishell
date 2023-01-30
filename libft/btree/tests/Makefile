# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:53:46 by pmarquis          #+#    #+#              #
#    Updated: 2022/11/19 20:15:08 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = test

LIBFTDIR = ../..
BTDIR = ..

OPT_DEBUG ?= 0

.PHONY: all clean fclean mrproper re $(LIBFTDIR)/libft.a $(BTDIR)/libftbtree.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror# -g -fsanitize=address

DEFINES =
ifeq ($(OPT_DEBUG),0)
DEFINES += -DNDEBUG
endif

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) -I$(BTDIR) -I$(LIBFTDIR) -o $@ $<

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): main.o $(BTDIR)/libftbtree.a $(LIBFTDIR)/libft.a
	$(CC) $(CFLAGS) $^ -o $@

$(BTDIR)/libftbtree.a:
	$(MAKE) -C $(BTDIR)

$(LIBFTDIR)/libft.a:
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

mrproper: fclean

re: fclean all

### deps
main.o: $(BTDIR)/ft_btree.h $(LIBFTDIR)/libft.h

