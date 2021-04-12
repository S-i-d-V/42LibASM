# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 13:11:34 by user42            #+#    #+#              #
#    Updated: 2021/04/12 18:47:22 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s

OBJS = $(SRCS:.s=.o)

TESTER_SRCS = tester_colors.c \
			tester_utils.c \
			tester_strlen.c \
			tester_strcpy.c \
			tester_strcmp.c

%.o: %.s
	nasm -f elf64 $< -o $@

all: $(NAME)
	ar rc $(NAME) $(OBJS)
	cc $(TESTER_SRCS) $(NAME) main.c

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f ./a.out

re: fclean all
