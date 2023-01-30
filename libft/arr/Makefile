# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 22:03:28 by pmarquis          #+#    #+#              #
#    Updated: 2022/12/26 08:02:33 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean mrproper re tests

NAME = libftarr.a

LIBFTDIR = ..

# options

OPT_DEBUG ?= 1
export OPT_DEBUG

# end options

CC = gcc

ifeq ($(OPT_DEBUG),1)
CFLAGS = -Wall -Wextra -g -fsanitize=address
else
CFLAGS = -Wall -Wextra -Werror
endif

INC = ft_arr.h $(LIBFTDIR)/libft.h
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

DEFINES =

ifeq ($(OPT_DEBUG),0)
DEFINES += -DNDEBUG
endif

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) -I$(LIBFTDIR) -o $@ $<

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f *.o
	$(MAKE) -C tests $@

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C tests $@

mrproper: fclean
	rm -f cscope.* tags
	$(MAKE) -C tests $@

re: fclean all

tests:
	$(MAKE) -C $@

### deps
$(OBJ): $(INC)
