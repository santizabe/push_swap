/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szapata- <szapata-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:39:04 by szapata-          #+#    #+#             */
/*   Updated: 2024/05/31 11:07:28 by szapata-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				num;
	unsigned int	pos;
	unsigned int	cost[2];
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_swap(t_list **lst);
void	ft_swap_two(t_list **lst_a, t_list **lst_b);
void	ft_push_node(t_list **src, t_list **dst);
void	ft_lstrotate(t_list **lst);
void	ft_lstrotate_two(t_list **lst_a, t_list **lst_b);
void	ft_lstrotate_rev(t_list **lst);
void	ft_lstrotate_rev_two(t_list **lst_a, t_list **lst_b);
int		ft_lstsize(t_list *lst);
int		ft_issorted(t_list *lst, int order);
int		*sort_list(t_list *lst);
void	calculate_steps(t_list *a, int *sorted_list);
void    calc_move(t_list **a, t_list **b, char order);
void	calc_costs(t_list **a, t_list **b, int order);
void    calc_targets(t_list *a, t_list *b, int order);
void    exec_moves(t_list **a, t_list **b, int *res, int order);
int		check_sorted(t_list *lst, int lstsize);
int		check_args(char **argv, int argc);
char	**ft_split_nums(int *argc, char *args);

#endif