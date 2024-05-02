/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_my_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:19 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/01 13:22:14 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack **a)
{
	int	temp;

	if (stack_size(*a) < 2)
		return ;
	if (*a && (*a)->next)
	{
		temp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = temp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
}

void	ra(t_stack **a)
{
	t_stack	*last;

	if (stack_size(*a) < 2)
		return ;
	if (*a && (*a)->next)
	{
		last = ft_lstlast(*a);
		last->next = *a;
		*a = (*a)->next;
		last->next->next = NULL;
	}
}

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stack_size(*a) < 2)
		return ;
	if (!(*a))
		return ;
	last = ft_lstlast(*a);
	before_last = *a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *a;
	*a = last;
}
