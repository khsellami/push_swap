/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:56:46 by ksellami          #+#    #+#             */
/*   Updated: 2024/04/20 21:15:30 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_stack **a)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = *a;
	while (curr)
	{
		tmp = *a;
		while (tmp)
		{
			if (curr->data > tmp->data)
				curr->index++;
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}

static bool	above_median(t_stack **b, int len_b, int biggest_index)
{
	int		middle;
	t_stack	*tmp;
	int		position;

	middle = len_b / 2;
	tmp = *b;
	position = 0;
	while (tmp)
	{
		if (tmp->index == biggest_index)
		{
			if (position < middle)
				return (true);
			else
				return (false);
		}
		position++;
		tmp = tmp->next;
	}
	return (false);
}

static void	push_all_to_a(t_stack **a, t_stack **b)
{
	int	len_b;
	int	biggest_index;

	while (*b)
	{
		len_b = stack_len(*b);
		biggest_index = len_b - 1;
		if ((*b)->index == biggest_index)
			pa(a, b);
		else if (above_median(b, len_b, biggest_index))
			rb(b);
		else
			rrb(b);
	}
}

static void	push_all_to_b(t_stack **a, t_stack **b, int range)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(b, a);
			i++;
		}
		else if ((*a)->index <= (i + range))
		{
			pb(b, a);
			if (stack_len(*b) > 1)
			{
				rb(b);
			}
			i++;
		}
		else
		{
			ra(a);
		}
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	len_a;
	int	range;

	len_a = stack_len(*a);
	if (len_a <= 100)
		range = 16;
	else
		range = 32;
	push_all_to_b(a, b, range);
	push_all_to_a(a, b);
}
