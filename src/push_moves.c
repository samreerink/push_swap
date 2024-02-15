/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   push_moves.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/06 15:21:54 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/07 18:33:03 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(t_stack **b, t_stack **a, bool print)
{
	push(&(*b)->head, &(*a)->head);
	if (print)
		write(STDOUT_FILENO, "pa\n", 3);
}

void	move_pb(t_stack **a, t_stack **b, bool print)
{
	push(&(*a)->head, &(*b)->head);
	if (print)
		write(STDOUT_FILENO, "pb\n", 3);
}
