/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:30:51 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/15 22:22:25 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*current;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->content = n;
	current = *stack;
	if (!current)
	{
		*stack = node;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node;
	}
}
