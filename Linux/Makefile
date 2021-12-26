ASM			=	nasm
ASM_FLGS	=	-f elf64
ASM_SRCS	=	ft_read.s ft_write.s ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s
ASM_OBJS	=	$(ASM_SRCS:%.s=%.o)
LIBASM		=	libasm.a

СС			=	gcc
CC_FLGS		=	-Wall -Wextra -Werror -L . -l asm
C_SRCS		=	test.c
TEST		=	test

.PHONY: all clean fclean re test

all: $(LIBASM)

clean:
	rm -f $(ASM_OBJS)

fclean: clean
	rm -f $(LIBASM) && rm -f $(TEST)

re: fclean all

test: $(TEST)

# * LIBRARY
$(LIBASM): $(ASM_OBJS)
	ar -rc $(LIBASM) $(ASM_OBJS)

%.o: %.s
	$(ASM) $(ASM_FLGS) $<

# * TEST

$(TEST):
	$(CC)  $(C_SRCS) $(CC_FLGS) -o $(TEST) -fPIC
