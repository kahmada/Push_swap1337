/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:04:37 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/01 13:19:48 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	if (((*a)->index > (*a)->next->index)
		&& ((*a)->index > (*a)->next->next->index))
	{
		ra(a);
		if (check_is_sorted(*a) == 0)
			sa(a);
	}
	else if (((*a)->index < (*a)->next->index)
		&& ((*a)->next->index > (*a)->next->next->index))
	{
		rra(a);
		if (check_is_sorted(*a) == 0)
			sa(a);
	}
	else
		sa(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	while (stack_size(*a) > 3)
	{
		min_node = find_smallest_node(*a);
		while (*a != min_node)
		{
			rra(a);
		}
		pb(a, b);
	}
	if (check_is_sorted(*a) == 0)
	{
		sort_3(a);
	}
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	while (stack_size(*a) > 3)
	{
		min_node = find_smallest_node(*a);
		set_position(a);
		while (*a != min_node)
		{
			if (min_node->position < 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	if (check_is_sorted(*a) == 0)
	{
		sort_3(a);
	}
	pa(a, b);
	pa(a, b);
}
