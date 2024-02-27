/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   checker.h                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/16 23:04:41 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/17 19:09:39 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				n;
	size_t			index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*last;
	char	***split_args;
}	t_stack;

void	error_exit(t_stack **stack_a, t_stack **stack_b);

void	checker(t_stack **a, t_stack **b);

void	init_stack(t_stack **new_stack);

void	free_stack(t_stack **stack);

bool	atoi_overflow(const char *str, int *nb);

bool	check_sorted(t_stack **stack);

bool	check_duplicate(t_stack **stack);

bool	check_digits(char *argv[]);

bool	split_arguments(int argc, char *argv[], t_stack **stack);

bool	make_stack(t_stack **stack);

bool	index_stack(t_stack **stack);

void	move_sa(t_stack **a, bool print);

void	move_sb(t_stack **b);

void	move_ss(t_stack **a, t_stack **b);

void	move_pa(t_stack **b, t_stack **a, bool print);

void	move_pb(t_stack **a, t_stack **b, bool print);

void	move_ra(t_stack **a, bool print);

void	move_rb(t_stack **b);

void	move_rr(t_stack **a, t_stack **b);

void	move_rra(t_stack **a, bool print);

void	move_rrb(t_stack **b);

void	move_rrr(t_stack **a, t_stack **b);

void	swap_first_two(t_node **head);

void	push(t_node **head_one, t_node **head_two);

void	rotate(t_node **head, t_node **last);

void	reverse_rotate(t_node **head, t_node **last);

#endif
