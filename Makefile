CC	=	nasm
FLAGS	=	-f elf

NAME	=	libasm.a
SRCS	=	ft_read.s ft_strcpy.s ft_strlen.s ft_strcmp.s ft_strdup.s ft_write.s
OBJS	=	$(SRCS:%.s=%.o)

.PHONY: all clean fclean re good

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.s
	$(CC) $(FLAGS) $<

