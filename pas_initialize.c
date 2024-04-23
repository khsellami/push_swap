/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pas_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:57:12 by ksellami          #+#    #+#             */
/*   Updated: 2024/04/23 12:38:07 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	append_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (!node)
		exit(1);
	node->data = n;
	node->next = NULL;
	if (!(*a))
		*a = node;
	else
	{
		last_node = ft_lstlast(*a);
		last_node->next = node;
	}
}

static int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->data == n)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	error_syntax(char *s)
{
	if (!s || !(*s == '+' || *s == '-' || ft_isdigit(*s)))
		return (1);
	s++;
	if(*s == '\0')
		return (1);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (1);
		s++;
	}
	return (0);
}

void	verifiee_initialize(t_stack **a, char *str)
{
	char	**result;
	int		i;
	int		j;
	long	n;

	result = ft_split(str, ' ');
	if (result == NULL || result[0] == NULL)
		error_free(a);
	i = 0;
	j = 0;
	while (result[j])
		j++;
	while (result[i])
	{
		n = ft_atoi(result[i]);
		if (error_syntax(result[i]) || n > INT_MAX || n < INT_MIN \
				|| error_duplicate(*a, (int)n))
		{
			ft_free_split(result, j);
			error_free(a);
		}
		append_node(a, (int)n);
		i++;
	}
	free_arg(result);
}
