/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:23:56 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/26 15:25:27 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
}

void	handle_error(t_stack **a, char **split_input)
{
	write (2, "Error\n", 6);
	free_stack(a);
	free_2d_array(split_input);
	exit(1);
}

void	free_stack(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	if (!a || !(*a))
	{
		return ;
	}
	current = *a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*a = NULL;
}
