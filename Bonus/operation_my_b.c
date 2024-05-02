/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_my_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:02:59 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/30 15:16:03 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_stack **b)
{
	int	temp;

	if (stack_size(*b) < 2)
		return ;
	if (*b && (*b)->next)
	{
		temp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = temp;
	}
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
}

void	rb(t_stack **b)
{
	t_stack	*last;

	if (stack_size(*b) < 2)
		return ;
	if (*b && (*b)->next)
	{
		last = ft_lstlast(*b);
		last->next = *b;
		*b = (*b)->next;
		last->next->next = NULL;
	}
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stack_size(*b) < 2)
		return ;
	before_last = *b;
	last = ft_lstlast(*b);
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *b;
	*b = last;
}
