/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:50:00 by ksellami          #+#    #+#             */
/*   Updated: 2024/04/20 20:59:31 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}				t_stack;	

char	**ft_split(char *s, char c);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char	*s2);
long	ft_atoi(char *s);
void	ft_free_split(char **split_strings, int count);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	rb(t_stack **b);
void	sb(t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rrb(t_stack **b);
void	verifiee_initialize(t_stack **a, char *str);
void	sorting(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_size_5(t_stack **a, t_stack **b);
void	create_index(t_stack **a);
void	push_swap(t_stack **a, t_stack **b);
int		stack_len(t_stack *stack);
int		stack_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
void	error_free(t_stack **a);
void	free_arg(char **str);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	sort_four(t_stack **a, t_stack **b);
#endif
