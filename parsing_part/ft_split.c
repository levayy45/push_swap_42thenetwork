/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzidini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:44:35 by tzidini           #+#    #+#             */
/*   Updated: 2025/10/18 14:45:19 by tzidini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++ ;
		if (s[i])
			count++ ;
		while (s[i] != c && s[i])
			i++ ;
	}
	return (count);
}

static char	*ft_word_dup(char const *s, int start, int end)
{
	return (ft_substr (s, start, end - start));
}

static void	ft_free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		if (split[i])
			free(split[i]);
		i++ ;
	}
	free(split);
}

static int	ft_fill_split(char const *s, char c, char **split)
{
	int	i;
	int	start;
	int	tmp;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++ ;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++ ;
		split[tmp] = ft_word_dup(s, start, i);
		if (!split[tmp])
		{
			ft_free_split(split, tmp);
			return (0);
		}
		tmp++ ;
	}
	split[tmp] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**split;

	if (!s)
		return (NULL);
	len = 1 + ft_count(s, c);
	split = (char **)malloc(len * sizeof(char *));
	if (!split)
		return (NULL);
	if (!ft_fill_split(s, c, split))
		return (NULL);
	return (split);
}
