/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:30:25 by kahmada           #+#    #+#             */
/*   Updated: 2024/04/27 15:10:56 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int				content;
	int				index;
	int				position;
	struct s_stack	*next;
}	t_stack;
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_check(char *str);
void	ft_checker(t_stack **a, t_stack **b);
void	read_input_operations(t_stack **a, t_stack **b);
void	execute_operation(t_stack **a, t_stack **b, char *op);
void	handle_error(t_stack **a, char **split_input);
void	ft_error(void);
void	free_2d_array(char **array);
void	free_stack(t_stack **a);
int		stack_size(t_stack *stack);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sb(t_stack **b);
void	pb(t_stack **a, t_stack **sb);
void	rb(t_stack **b);
void	rrb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
t_stack	*ft_lstlast(t_stack *lst);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	**ft_split(char *str);
long	ft_atoi(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		is_valid_arg(char *str);
int		has_duplicates(t_stack *stack, int num);
void	initialise_stack_a(t_stack **a, char *av);
void	fill_stack(t_stack **stack, int n);
int		check_is_sorted(t_stack *stack);
#endif
