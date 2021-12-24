ASM		=	nasm
FLAGS	=	-f elf64

NAME	=	libasm.a
SRCS	=	ft_read.s #ft_strcpy.s ft_strlen.s ft_strcmp.s ft_strdup.s ft_write.s
OBJS	=	$(SRCS:%.s=%.o)

CC			=	gcc
TEST		=	out
TEST_C		=	tests.c
DEPENDENCY	=	-L . -l asm

.PHONY: all clean fclean re test

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(TEST)

$(NAME): $(OBJS)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.s
	$(ASM) $(FLAGS) $<

$(TEST): $(TEST_C) $(NAME)
	$(CC) $(TEST_C) $(DEPENDENCY) -o $(TEST)