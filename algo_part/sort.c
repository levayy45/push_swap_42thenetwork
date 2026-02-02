/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzidini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:03:11 by tzidini           #+#    #+#             */
/*   Updated: 2026/01/23 15:03:12 by tzidini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_position(t_node *stack, int rank_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == rank_index)
			return (pos);
		pos++ ;
		stack = stack->next;
	}
	return (-1);
}

static void	push_all_to_b(t_node **a, t_node **b, int chunk_size)
{
	int	count;

	count = 0;
	while (*a)
	{
		if ((*a)->index <= count)
		{
			pb(a, b);
			rb(b, 1);
			count++ ;
		}
		else if ((*a)->index <= count + chunk_size)
		{
			pb(a, b);
			count++ ;
		}
		else
			ra(a, 1);
	}
}

static void	push_all_to_a(t_node **a, t_node **b)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		max = size - 1;
		pos = find_position(*b, max);
		if (pos <= (max + 1) / 2)
		{
			while ((*b)->index != max)
				rb(b, 1);
		}
		else
		{
			while ((*b)->index != max)
				rrb(b, 1);
		}
		pa(a, b);
	}
}

void	butterfly_sort(t_node **a_stack, t_node **b_stack)
{
	int	chunk_size;
	int	size;

	size = stack_size(*a_stack);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_all_to_b(a_stack, b_stack, chunk_size);
	push_all_to_a(a_stack, b_stack);
}
