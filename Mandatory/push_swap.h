/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:30:25 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/26 21:13:18 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				position;
	struct s_stack	*next;
}	t_stack;
void	handle_error(t_stack **a, char **split_input);
void	free_2d_array(char **array);
void	free_stack(t_stack **a);
int		stack_size(t_stack *stack);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sb(t_stack **b);
void	pb(t_stack **a, t_stack **sb);
void	rb(t_stack **b);
void	rrb(t_stack **b);
t_stack	*ft_lstlast(t_stack *lst);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	**ft_split(char *str);
long	ft_atoi(char *s);
int		ft_isdigit(int c);
int		is_valid_arg(char *str);
int		has_duplicates(t_stack *stack, int num);
void	initialise_stack_a(t_stack **a, char *av);
void	fill_stack(t_stack **stack, int n);
void	sort_all(t_stack *a, t_stack *b);
int		check_is_sorted(t_stack *stack);
void	indexing(t_stack **stacka);
void	sort_algorithm(t_stack **stack_a, t_stack **stack_b, int range);
void	set_position(t_stack **stack);
int		is_above_median(t_stack **stack_b);
void	push_back_to_a(t_stack **a, t_stack **b);
t_stack	*find_smallest_node(t_stack *stack);
#endif
