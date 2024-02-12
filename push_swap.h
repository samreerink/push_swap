/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   push_swap.h                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/12 14:34:14 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/12 20:19:13 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int		n;
	size_t		index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*last;
	char	***split_args;
}	t_stack;

void	radix_sort(t_stack **a, t_stack **b, size_t len);

void	sort_three(t_stack **a);

void	sort_four(t_stack **a, t_stack **b);

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
