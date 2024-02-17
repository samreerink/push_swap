/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   moves_rotate.c                                    :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/06 16:37:51 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/17 19:24:14 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	move_ra(t_stack **a, bool print)
{
	rotate(&(*a)->head, &(*a)->last);
	if (print)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	move_rb(t_stack **b)
{
	rotate(&(*b)->head, &(*b)->last);
}

void	move_rr(t_stack **a, t_stack **b)
{
	rotate(&(*a)->head, &(*a)->last);
	rotate(&(*b)->head, &(*b)->last);
}
