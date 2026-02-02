/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzidini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:40:57 by tzidini           #+#    #+#             */
/*   Updated: 2026/01/23 20:40:58 by tzidini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap_algorithm(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size <= 5)
		sort_small(stack_a, stack_b, size);
	else
		butterfly_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_node	*a_stack;
	t_node	*b_stack;

	if (ac < 2)
		return (0);
	a_stack = NULL;
	b_stack = NULL;
	parse_input(&a_stack, av);
	stack_indices(a_stack);
	if (!is_sorted(a_stack))
		push_swap_algorithm(&a_stack, &b_stack);
	free_stack(&a_stack);
	free_stack(&b_stack);
	return (0);
}
