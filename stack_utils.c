/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:56:35 by ksellami          #+#    #+#             */
/*   Updated: 2024/04/12 18:57:50 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack	*temp;
	int		size;

	temp = stack;
	size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_arg(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
