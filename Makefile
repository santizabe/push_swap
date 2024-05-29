NAME = push_swap

SRC = args_checker.c calculate_steps.c check_sorted.c ft_split_nums.c \
	main.c sort_list.c utils/ft_issorted.c utils/ft_lstnew.c utils/ft_lstsize.c \
	utils/ft_lstadd_back.c utils/ft_lstrotate.c utils/ft_push_node.c \
	utils/ft_lstadd_front.c utils/ft_lstrotate


OBJ = $(SRC:c=o)

$(NAME): $(OBJ)
	ar rcs push_swap.a $(OBJ)

all: $(NAME)
	cc $(CFLAGS) -o $(NAME) main.c libft/libft.a push_swap.a

clean:
	@rm -f utils/*.o
	@rm -f *.o

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re