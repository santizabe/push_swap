NAME = push_swap

SRC = $(wildcard utils/*.c) $(wildcard *.c) 

OBJ = $(SRC:c=o)

$(NAME): $(OBJ)
	ar rcs push_swap.a $(OBJ)

all: $(NAME)
	@make -C printf
	cc $(CFLAGS) -o $(NAME) main.c printf/libftprintf.a push_swap.a

clean:
	@make clean -C printf
	@rm -f utils/*.o
	@rm -f *.o

fclean:
	@make fclean -C printf
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re