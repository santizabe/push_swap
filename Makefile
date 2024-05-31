NAME = push_swap

SRC = args_checker.c calculate_steps.c ft_split_nums.c \
	sort_list.c calc_costs.c calc_moves.c\
	utils/ft_issorted.c utils/ft_lstnew.c \
	utils/ft_lstsize.c utils/ft_lstadd_back.c \
	utils/ft_lstrotate.c utils/ft_push_node.c \
	utils/ft_lstadd_front.c utils/ft_lstrotate_rev.c \
	utils/ft_lstrotate_rev_two.c utils/ft_lstrotate_two.c \
	utils/ft_swap_two.c utils/ft_lstclear.c utils/ft_swap.c \
	utils/ft_lstdelone.c

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

$(NAME): $(OBJ)
	@cc $(CFLAGS) -o $(NAME) $(SRC) main.c libft/libft.a

all: $(NAME) clean

clean:
	@rm -f utils/*.o
	@rm -f *.o

fclean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re