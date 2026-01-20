NAME = push_swap

BONUS = checker

SRC = args_checker.c calculate_steps.c ft_split_nums.c \
	sort_list.c calc_costs.c calc_moves.c exec_moves.c \
	get_targets.c exec_moves_utils.c  order_list.c\
	utils/ft_issorted.c utils/ft_lstnew.c ft_atol.c\
	utils/ft_lstsize.c utils/ft_lstadd_back.c \
	utils/ft_lstrotate.c utils/ft_push_node.c \
	utils/ft_lstadd_front.c utils/ft_lstrotate_rev.c \
	utils/ft_lstrotate_rev_two.c utils/ft_lstrotate_two.c \
	utils/ft_swap_two.c utils/ft_lstclear.c utils/ft_swap.c \
	utils/ft_lstdelone.c

LIBFT = libft/libft.a

SRC_B = read.c

OBJ = $(SRC:c=o)

B_OBJ = $(SRC_B:c=o)

CFLAGS = -Wall -Werror -Wextra

%.o: %.c
	@gcc ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@clang $(CFLAGS) -o $(NAME) $(OBJ) main.c $(LIBFT)

$(LIBFT):
	@make -sC libft

all: $(NAME)

bonus: $(B_OBJ) $(OBJ)
	@clang $(CFLAGS) -o $(BONUS) $(B_OBJ) $(OBJ) bonus.c libft/libft.a
	@make clean

clean:
	@rm -f utils/*.o
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

fclean_b: clean
	@rm -f $(BONUS)

re: fclean all

re_b: fclean_b bonus

.PHONY: all clean fclean re
