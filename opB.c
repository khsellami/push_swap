/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opB.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:46:55 by ksellami          #+#    #+#             */
/*   Updated: 2024/04/12 18:46:55 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	curr = ft_lstlast(*b);
	curr->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	sb(t_stack **b)
{
	int	temp;

	if (!(*b))
		return ;
	temp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = temp;
	write(1, "sb\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, tmp);
	write(1, "pb\n", 3);
}

void	rrb(t_stack **b)
{
	t_stack	*current;
	t_stack	*prev;

	if (!(*b))
		return ;
	current = *b;
	prev = NULL;
	while (current -> next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *b;
	*b = current;
	write(1, "rrb\n", 4);
}
