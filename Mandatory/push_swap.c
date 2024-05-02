/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:00:15 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/01 13:38:22 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_stack_a(t_stack **a, char *tmp)
{
	char	**split_input;
	int		i;
	long	n;

	split_input = ft_split(tmp);
	if (split_input[0] == NULL)
		handle_error(a, split_input);
	i = 0;
	while (split_input[i])
	{
		if (is_valid_arg(split_input[i]) == 1)
		{
			handle_error(a, split_input);
		}
		n = ft_atoi(split_input[i]);
		if ((n > INT_MAX || n < INT_MIN) || has_duplicates(*a, n) == 1)
		{
			handle_error(a, split_input);
		}
		fill_stack(a, (int)n);
		i++;
	}
	free_2d_array(split_input);
}

void	sort_all(t_stack *a, t_stack *b)
{
	indexing(&a);
	if (stack_size(a) == 2)
		sa(&a);
	else if (stack_size(a) == 3)
		sort_3(&a);
	else if (stack_size(a) == 4)
		sort_4(&a, &b);
	else if (stack_size(a) == 5)
		sort_5(&a, &b);
	else if (stack_size(a) <= 100)
		sort_algorithm(&a, &b, 16);
	else
		sort_algorithm(&a, &b, 32);
	free_stack(&a);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	*res;

	a = NULL;
	b = NULL;
	res = NULL;
	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			res = ft_strjoin(res, argv[i++]);
			res = ft_strjoin(res, " ");
		}
		initialise_stack_a(&a, res);
		free(res);
		if (check_is_sorted(a) == 1)
			return (free_stack(&a), 0);
		sort_all(a, b);
	}
	return (0);
}
