/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:48:33 by ksellami          #+#    #+#             */
/*   Updated: 2024/04/12 18:48:33 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	temp;

	if (!(*a))
		return ;
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, tmp);
	write(1, "pa\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	curr = ft_lstlast(*a);
	curr->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*current;
	t_stack	*prev;

	if (!(*a))
		return ;
	current = *a;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *a;
	*a = current;
	write(1, "rra\n", 4);
}
