# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:53:46 by pmarquis          #+#    #+#              #
#    Updated: 2022/11/20 03:49:51 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = test

LIBFTDIR = ../..
BTDIR = ../../btree
DIR = ..

OPT_DEBUG ?= 0

.PHONY: all clean fclean mrproper re $(LIBFTDIR)/libft.a \
	$(BTDIR)/libftbtree.a $(DIR)/libftdict.a

CC = gcc
CFLAGS = -Wall -Wextra #-Werror# -g -fsanitize=address

DEFINES =
ifeq ($(OPT_DEBUG),0)
DEFINES += -DNDEBUG
endif

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) -I$(BTDIR) -I$(LIBFTDIR) -I$(DIR) -o $@ $<

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): main.o $(DIR)/libftdict.a $(BTDIR)/libftbtree.a $(LIBFTDIR)/libft.a
	$(CC) $(CFLAGS) $^ -o $@

$(DIR)/libftdict.a:
	$(MAKE) -C $(DIR)

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
main.o: $(DIR)/ft_dict.h $(BTDIR)/ft_btree.h $(LIBFTDIR)/libft.h

