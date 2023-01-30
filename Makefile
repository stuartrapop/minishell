# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 08:39:46 by pmarquis          #+#    #+#              #
#    Updated: 2023/01/30 21:35:44 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean mrproper re

OPT_DEBUG ?= 1
export OPT_DEBUG

ifeq ($(shell uname),Linux)
OPT_LINUX ?= 1
else
OPT_LINUX ?= 0
endif
export OPT_LINUX

OPT_MEMLIST ?= 1
export OPT_MEMLIST

NAME = minishell

CC = gcc

ifeq ($(OPT_DEBUG),1)
CFLAGS = -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer
else
CFLAGS = -Wall -Wextra -Werror
endif

INCDIR = src
SRCDIR = src
LIBFTDIR = libft

INC = $(wildcard $(INCDIR)/*.h) $(LIBFTDIR)/arr/ft_arr.h \
	  $(LIBFTDIR)/gnl/ft_getnext.h $(LIBFTDIR)/printf/ft_printf.h \
	  $(LIBFTDIR)/libft.h
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

DEFINES =

ifeq ($(OPT_DEBUG),0)
DEFINES += -DNDEBUG
endif

ifeq ($(OPT_LINUX),1)
DEFINES += -DLINUX
endif

INCLUDES = -I$(INCDIR) -I$(LIBFTDIR)/arr -I$(LIBFTDIR)/gnl \
		   -I$(LIBFTDIR)/printf -I$(LIBFTDIR)

ifeq ($(OPT_LINUX),0)
INCLUDES += -I/Users/$(USER)/.brew/opt/readline/include
endif

ARCHIVES = $(LIBFTDIR)/arr/libftarr.a $(LIBFTDIR)/gnl/libftgnl.a \
		   $(LIBFTDIR)/printf/libftprintf.a $(LIBFTDIR)/libft.a

ifeq ($(OPT_LINUX),1)
LIBS = -lreadline
else
LIBS = -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
endif

.c.o:
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

.DEFAULT_GOAL = all

all: $(NAME)

$(NAME): $(OBJ) $(ARCHIVES)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(LIBFTDIR)/libft.a:
	$(MAKE) -C $(LIBFTDIR)

$(LIBFTDIR)/gnl/libftgnl.a:
	$(MAKE) -C $(LIBFTDIR)/gnl

$(LIBFTDIR)/arr/libftarr.a:
	$(MAKE) -C $(LIBFTDIR)/arr

$(LIBFTDIR)/printf/libftprintf.a:
	$(MAKE) -C $(LIBFTDIR)/printf

clean:
	rm -f $(SRCDIR)/*.o
	$(MAKE) -C $(LIBFTDIR) $@

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) $@

mrproper: fclean
	rm -f cscope.* tags
	$(MAKE) -C $(LIBFTDIR) $@

re: fclean all

### deps
$(OBJ): $(INC)
