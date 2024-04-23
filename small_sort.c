/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:58:31 by ksellami          #+#    #+#             */
/*   Updated: 2024/04/16 10:27:37 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if (((*a)->data > (*a)->next->data) \
			&& ((*a)->data > (*a)->next->next->data))
	{
		ra(a);
		if (stack_sorted(*a))
			return ;
		sa(a);
	}
	else if (((*a)->data < (*a)->next->data) \
			&& ((*a)->next->data > (*a)->next->next->data))
	{
		rra(a);
		if (stack_sorted(*a))
			return ;
		sa(a);
	}
	else if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	while ((*a)->index != 0)
		ra(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_size_5(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		if ((*a)->index < 2)
			pb(b, a);
		else
			ra(a);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
	if (!stack_sorted(*a))
		sa(a);
}

void	sorting(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) == 4)
		sort_four(a, b);
	else if (stack_len(*a) == 5)
		sort_size_5(a, b);
	else
		push_swap(a, b);
}
