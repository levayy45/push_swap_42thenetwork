/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzidini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:51:41 by tzidini           #+#    #+#             */
/*   Updated: 2026/01/23 15:51:46 by tzidini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_three(t_node **a_stack)
{
	int	a;
	int	b;
	int	c;

	a = (*a_stack)->value;
	b = (*a_stack)->next->value;
	c = (*a_stack)->next->next->value;
	if (a > b && a > c)
	{
		ra(a_stack, 1);
		if (b > c)
			sa(a_stack, 1);
	}
	else if (b > a && b > c)
	{
		sa(a_stack, 1);
		ra(a_stack, 1);
		if (a > c)
			sa(a_stack, 1);
	}
	else if (c > a && c > b)
	{
		if (a > b)
			sa(a_stack, 1);
	}
}

void	sort_four(t_node **a_stack, t_node **b_stack)
{
	rotate_to_min(a_stack);
	pb(a_stack, b_stack);
	sort_three(a_stack);
	pa(a_stack, b_stack);
}

void	sort_five(t_node **a_stack, t_node **b_stack)
{
	rotate_to_min(a_stack);
	pb(a_stack, b_stack);
	sort_four(a_stack, b_stack);
	pa(a_stack, b_stack);
}

void	sort_small(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
