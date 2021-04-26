RED =`tput setaf 1`
GREEN =`tput setaf 2`
CLEAR =`tput sgr0`

NAME = libasm.a

NAME_TESTER = Libasm_tester

SRCS = ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s	\
	ft_write.s	\
	ft_read.s	\
	ft_strdup.s

OBJS = $(SRCS:.s=.o)

TESTER_SRCS = Tester/tester_colors.c \
			Tester/tester_utils.c \
			Tester/tester_strlen.c \
			Tester/tester_strcpy.c \
			Tester/tester_strcmp.c \
			Tester/tester_write.c \
			Tester/tester_read.c \
			Tester/tester_strdup.c

%.o: %.s
	nasm -f elf64 $< -o $@

all: $(NAME)

test: $(NAME)
	@cc $(TESTER_SRCS) $(NAME) main.c -o $(NAME_TESTER)
	@echo "$(GREEN)$(NAME_TESTER) compiled with success.$(CLEAR)"
	@echo "Commande : ./Libasm_tester (-test) pour montrer les tests."

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled with success.$(CLEAR)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)Objects deleted with success.$(CLEAR)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_TESTER)
	@echo "$(RED)$(NAME) & $(NAME_TESTER) deleted.$(CLEAR)"

re: fclean all
