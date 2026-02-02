/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzidini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:00:22 by tzidini           #+#    #+#             */
/*   Updated: 2026/01/22 22:00:24 by tzidini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valide_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++ ;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	is_in_range(const char *str)
{
	long	n;

	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

static	void	valide_args(t_node **stack, char **av)
{
	t_node	*node;
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!is_valide_number(av[i]) || !is_in_range(av[i]))
			free_error(stack, av);
		n = ft_atol(av[i]);
		if (check_duplicates(*stack, (int)n))
			free_error(stack, av);
		node = ft_lstnew(n);
		if (!node)
			free_error(stack, av);
		stack_add_back(stack, node);
		i++ ;
	}
}

void	parse_input(t_node **stack_a, char **av)
{
	char	**args;
	int		i;

	i = 1;
	while (av[i])
	{
		args = ft_split(av[i], ' ');
		if (!args || !args[0])
		{
			if (args)
				free(args);
			error_exit(stack_a, NULL);
		}
		valide_args(stack_a, args);
		free_av(args);
		i++ ;
	}
}
