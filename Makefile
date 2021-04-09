# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 13:11:34 by user42            #+#    #+#              #
#    Updated: 2021/04/09 19:27:21 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s

OBJS = $(SRCS:.s=.o)

%.o: %.s
	nasm -f elf64 $< -o $@

all: $(NAME)
	ar rc $(NAME) $(OBJS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f ./a.out

re: fclean all
