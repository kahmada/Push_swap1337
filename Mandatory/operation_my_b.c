/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_my_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:02:59 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/16 18:17:51 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	int	temp;

	if (*b && (*b)->next)
	{
		temp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = temp;
	}
	write(1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *b;
	*b = *a;
	*a = (*b)->next;
	(*b)->next = tmp;
	write(1, "pb\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*last;

	if (*b && (*b)->next)
	{
		last = ft_lstlast(*b);
		last->next = *b;
		*b = (*b)->next;
		last->next->next = NULL;
	}
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!(*b))
		return ;
	before_last = *b;
	last = ft_lstlast(*b);
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}
