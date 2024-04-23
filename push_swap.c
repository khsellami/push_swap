/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:49:09 by ksellami          #+#    #+#             */
/*   Updated: 2024/04/23 12:38:18 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_all(int ac, char **av)
{
	char	*res;
	int		i;

	res = NULL;
	i = 1;
	while (i < ac)
	{
		res = ft_strjoin(res, av[i]);
		res = ft_strjoin(res, " ");
		i++;
	}
	return (res);
}

static int	just_spaces(char *s)
{
	while (*s != '\0')
	{
		if (*s != ' ' && !(*s >= 9 && *s <= 13))
			return (0);
		s++;
	}
	return (1);
}

static int	is_empty(char *s)
{
	if (s == NULL || s[0] == '\0' || just_spaces(s))
		return (1);
	return (0);
}

static void	empty_arg_free_error(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_empty(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*args;

	a = NULL;
	b = NULL;
	args = NULL;
	if (ac == 1)
		return (1);
	empty_arg_free_error(ac, av);
	if (ac >= 2)
	{
		args = join_all(ac, av);
		verifiee_initialize(&a, args);
		free(args);
	}
	create_index(&a);
	if (!stack_sorted(a))
		sorting(&a, &b);
	free_stack(&a);
	return (0);
}
