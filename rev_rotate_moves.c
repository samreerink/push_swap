/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   rev_rotate_moves.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/06 16:47:44 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/07 18:12:31 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rra(t_stack **a)
{
	reverse_rotate(&(*a)->head, &(*a)->last);
	write(STDOUT_FILENO, "rra\n", 4);
}

void	move_rrb(t_stack **b)
{
	reverse_rotate(&(*b)->head, &(*b)->last);
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	move_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(&(*a)->head, &(*a)->last);
	reverse_rotate(&(*b)->head, &(*b)->last);
	write(STDOUT_FILENO, "rrr\n", 4);
}
