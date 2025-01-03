# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzary <mzary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 13:16:20 by mzary             #+#    #+#              #
#    Updated: 2024/12/18 13:35:49 by mzary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_putstr_fd.c ft_strlcpy.c ft_strlen.c ft_strncmp.c
OBJ = $(SRC:.c=.o)

all: libft.a

libft.a: $(OBJ)
	ar rcs ../libft.a $^

%.o: %.c libft.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean

re: fclean all

PHONY: clean