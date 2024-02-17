/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   checker.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/16 23:34:59 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/17 21:13:07 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	apply_move(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "sa\n", 3))
		move_sa(a, false);
	else if (!ft_strncmp(move, "sb\n", 3))
		move_sb(b);
	else if (!ft_strncmp(move, "ss\n", 3))
		move_ss(a, b);
	else if (!ft_strncmp(move, "ra\n", 3))
		move_ra(a, false);
	else if (!ft_strncmp(move, "rb\n", 3))
		move_rb(b);
	else if (!ft_strncmp(move, "rr\n", 3))
		move_rr(a, b);
	else if (!ft_strncmp(move, "rra\n", 4))
		move_rra(a, false);
	else if (!ft_strncmp(move, "rrb\n", 4))
		move_rrb(b);
	else if (!ft_strncmp(move, "rrr\n", 4))
		move_rrr(a, b);
	else if (!ft_strncmp(move, "pa\n", 3))
		move_pa(b, a, false);
	else if (!ft_strncmp(move, "pb\n", 3))
		move_pb(a, b, false);
	else
		return (false);
	return (true);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*move;

	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		if (!apply_move(a, b, move))
		{
			free(move);
			error_exit(a, b);
		}
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	if ((*a)->head && check_sorted(a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}
