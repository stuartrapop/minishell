# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 00:44:59 by pmarquis          #+#    #+#              #
#    Updated: 2022/12/26 08:11:02 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean mrproper re tests

NAME = libftbtree.a

LIBFTDIR = ..

# options

OPT_DEBUG ?= 0
export OPT_DEBUG

# end options

CC = gcc

ifeq ($(OPT_DEBUG),1)
CFLAGS = -Wall -Wextra -g -fsanitize=address
else
CFLAGS = -Wall -Wextra -Werror
endif

INC = ft_btree.h $(LIBFTDIR)/libft.h
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

DEFINES =

ifeq ($(OPT_DEBUG),0)
DEFINES += -DNDEBUG
OBJ := $(filter-out ft_btnode_debug.o,$(OBJ))
endif

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) -I$(LIBFTDIR) -o $@ $<

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
ft_btnode_remove.o: ft_btnode_remove.h

