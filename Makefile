# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/09 13:11:34 by user42            #+#    #+#              #
#    Updated: 2021/04/14 02:48:34 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s	\
	ft_write.s	\
	ft_read.s

OBJS = $(SRCS:.s=.o)

TESTER_SRCS = Tester/tester_colors.c \
			Tester/tester_utils.c \
			Tester/tester_strlen.c \
			Tester/tester_strcpy.c \
			Tester/tester_strcmp.c \
			Tester/tester_write.c \
			Tester/tester_read.c

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
