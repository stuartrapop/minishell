# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarquis <astrorigin@protonmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 00:49:17 by pmarquis          #+#    #+#              #
#    Updated: 2022/12/17 00:58:30 by pmarquis         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean mrproper

main.o: main.c
	gcc -c -I.. -I../.. -o $@ $<

test: main.o ../libftgnl.a ../../libft.a
	gcc $^ -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f test

mrproper: fclean

