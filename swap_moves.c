/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   swap_moves.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/06 15:06:51 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/07 19:46:48 by sreerink      ########   odam.nl         */
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
	write(STDOUT_FILENO, "sb\n", 3);
}

void	move_ss(t_stack **a, t_stack **b)
{
	swap_first_two(&(*a)->head);
	swap_first_two(&(*b)->head);
	write(STDOUT_FILENO, "ss\n", 3);
}
