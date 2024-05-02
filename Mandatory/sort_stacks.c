/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:18:44 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/26 18:26:29 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algorithm(t_stack **stack_a, t_stack **stack_b, int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			pb(stack_a, stack_b);
			if (stack_size(*stack_b) > 1)
			{
				rb(stack_b);
			}
			i++;
		}
		else
		{
			ra(stack_a);
		}
	}
	push_back_to_a(stack_a, stack_b);
}

void	set_position(t_stack **stack)
{
	t_stack	*current;
	int		position;

	current = *stack;
	position = 0;
	while (current != NULL)
	{
		current->position = position++;
		current = current->next;
	}
}

int	is_above_median(t_stack **stack_b)
{
	int		size;
	int		mid;
	t_stack	*top_element;

	set_position(stack_b);
	size = stack_size(*stack_b);
	mid = size / 2;
	top_element = *stack_b;
	while (top_element)
	{
		if (top_element->index == stack_size(*stack_b) - 1)
		{
			if (top_element->position < mid)
				return (1);
			return (0);
		}
		top_element = top_element->next;
	}
	return (0);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == (stack_size(*stack_b) - 1))
		{
			pa(stack_a, stack_b);
		}
		else
		{
			if (is_above_median(stack_b))
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}
