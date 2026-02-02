/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzidini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:26:44 by tzidini           #+#    #+#             */
/*   Updated: 2026/01/23 20:26:46 by tzidini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	rotate_to_min(t_node **stack_a)
{
	int		min;
	int		pos;
	int		size;
	t_node	*tmp;

	min = find_the_min(*stack_a);
	pos = 0;
	size = stack_size(*stack_a);
	tmp = *stack_a;
	while (tmp->value != min)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while ((*stack_a)->value != min)
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->value != min)
			rra(stack_a, 1);
	}
}

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	stack_indices(t_node *stack)
{
	int		count;
	t_node	*head;
	t_node	*curr;

	head = stack;
	while (head)
	{
		count = 0;
		curr = stack;
		while (curr)
		{
			if (curr->value < head->value)
				count++;
			curr = curr->next;
		}
		head->index = count;
		head = head->next;
	}
}
