/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   swap_moves.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/06 15:06:51 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/15 15:49:11 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_stack **a, bool print)
{
	swap_first_two(&(*a)->head);
	if (print)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	move_sb(t_stack **b)
{
	swap_first_two(&(*b)->head);
}

void	move_ss(t_stack **a, t_stack **b)
{
	swap_first_two(&(*a)->head);
	swap_first_two(&(*b)->head);
}
