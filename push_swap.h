/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzidini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:01:54 by tzidini           #+#    #+#             */
/*   Updated: 2026/01/22 17:01:56 by tzidini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void	sort_two(t_node **a);
void	sort_three(t_node **a_stack);
void	sort_four(t_node **a_stack, t_node **b_stack);
void	sort_five(t_node **a_stack, t_node **b_stack);
void	sort_small(t_node **stack_a, t_node **stack_b, int size);
void	butterfly_sort(t_node **a_stack, t_node **b_stack);
void	rotate_to_min(t_node **stack_a);
void	stack_indices(t_node *stack);
void	stack_add_back(t_node **stack, t_node *new);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b);
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b);
void	free_stack(t_node **stack);
void	error_exit(t_node **stack_a, t_node **stack_b);
void	free_av(char **av);
void	free_error(t_node **stack, char **av);
void	parse_input(t_node **stack_a, char **av);

size_t	ft_strlen(char const *str);

long	ft_atol(const char *str);

int		find_the_min(t_node *stack);
int		is_sorted(t_node *stack);
int		check_duplicates(t_node *stack, int n);
int		stack_size(t_node *stack);

t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lstnew(int value);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif
