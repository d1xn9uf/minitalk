# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzary <mzary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 14:45:06 by mzary             #+#    #+#              #
#    Updated: 2025/01/11 23:42:24 by mzary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client
BNAME = server_bonus client_bonus
CC = cc -Wall -Wextra -Werror

UTILS = utils/ft_atoi.c \
		utils/ft_itoa.c \
		utils/ft_putchar_fd.c \
		utils/ft_putendl_fd.c \
		utils/ft_putnbr_fd.c \
	 	utils/ft_putstr_fd.c \
		utils/ft_strlcpy.c \
		utils/ft_strlen.c \
		utils/ft_strncmp.c
UTILS_OBJ = $(UTILS:.c=.o)

all: $(NAME)

server: server.o $(UTILS_OBJ)
	$(CC) $^ -o $@

client: client.o $(UTILS_OBJ)
	$(CC) $^ -o $@

bonus: $(BNAME)

server_bonus: server_bonus.o $(UTILS_OBJ)
	$(CC) $^ -o $@

client_bonus: client_bonus.o $(UTILS_OBJ)
	$(CC) $^ -o $@

ft_%.o: ft_%.c utils/utils.h
	$(CC) -c $< -o $@

%_bonus.o: %_bonus.c minitalk_bonus.h
	$(CC) -c $< -o $@

%.o: %.c minitalk.h
	$(CC) -c $< -o $@

clean:
	rm -f $(UTILS_OBJ) client.o server.o client_bonus.o server_bonus.o

fclean: clean
	rm -f server client server_bonus client_bonus

re: fclean all

.PHONY: clean