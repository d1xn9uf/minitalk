# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzary <mzary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 14:45:06 by mzary             #+#    #+#              #
#    Updated: 2025/01/02 22:48:21 by mzary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client
CC = cc -Wall -Wextra -Werror

all: $(NAME)

server: server.c minitalk.h libft.a
	$(CC) server.c libft.a -o server

client: client.c minitalk.h libft.a
	$(CC) client.c libft.a -o client

libft.a:
	make -C libft

bonus: server_bonus client_bonus

server_bonus: server_bonus.c minitalk_bonus.h libft.a
	$(CC) server_bonus.c libft.a -o server_bonus

client_bonus: client_bonus.c minitalk_bonus.h libft.a
	$(CC) client_bonus.c libft.a -o client_bonus

clean:
	rm -f libft.a
	make clean -C libft

fclean: clean
	rm -f server client server_bonus client_bonus

re: fclean all

PHONY: clean