/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:06:19 by kahmada           #+#    #+#             */
/*   Updated: 2024/05/01 13:34:02 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	*res;

	a = NULL;
	b = NULL;
	res = NULL;
	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			res = ft_strjoin(res, av[i++]);
			res = ft_strjoin(res, " ");
		}
		initialise_stack_a(&a, res);
		free(res);
		ft_checker(&a, &b);
	}
	return (0);
}

void	read_input_operations(t_stack **a, t_stack **b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		execute_operation(a, b, op);
		free(op);
	}
}

void	execute_operation(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 1)
		sa(a);
	else if (ft_strcmp(op, "sb\n") == 1)
		sb(b);
	else if (ft_strcmp(op, "ss\n") == 1)
		ss(a, b);
	else if (ft_strcmp(op, "ra\n") == 1)
		ra(a);
	else if (ft_strcmp(op, "rb\n") == 1)
		rb(b);
	else if (ft_strcmp(op, "rr\n") == 1)
		rr(a, b);
	else if (ft_strcmp(op, "rrr\n") == 1)
		rrr(a, b);
	else if (ft_strcmp(op, "rra\n") == 1)
		rra(a);
	else if (ft_strcmp(op, "rrb\n") == 1)
		rrb(b);
	else if (ft_strcmp(op, "pa\n") == 1)
		pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 1)
		pb(a, b);
	else
		ft_error();
}

void	ft_checker(t_stack **a, t_stack **b)
{
	read_input_operations(a, b);
	if (check_is_sorted(*a) == 1 && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
}
