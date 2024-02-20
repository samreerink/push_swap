/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   moves_rev_rotate.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/06 16:47:44 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/19 23:11:31 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_rra(t_stack **a, bool print)
{
	reverse_rotate(&(*a)->head, &(*a)->last);
	if (print)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	move_rrb(t_stack **b)
{
	reverse_rotate(&(*b)->head, &(*b)->last);
}

void	move_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(&(*a)->head, &(*a)->last);
	reverse_rotate(&(*b)->head, &(*b)->last);
}
