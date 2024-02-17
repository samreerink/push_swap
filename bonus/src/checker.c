/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   checker.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/16 23:34:59 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/17 01:58:12 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	apply_move(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "sa", 3))
		move_sa(a, false);
	else if (!ft_strncmp(move, "sb", 3))
		move_sb(b);
	else if (!ft_strncmp(move, "ss", 3))
		move_ss(a, b);
	else if (!ft_strncmp(move, "ra", 3))
		move_ra(a, false);
	else if (!ft_strncmp(move, "rb", 3))
		move_rb(b);
	else if (!ft_strncmp(move, "rr", 3))
		move_rr(a, b);
	else if (!ft_strncmp(move, "rra", 4))
		move_rra(a, false);
	else if (!ft_strncmp(move, "rrb", 4))
		move_rrb(b);
	else if (!ft_strncmp(move, "rrr", 4))
		move_rrr(a, b);
	else if (!ft_strncmp(move, "pa", 3))
		move_pa(b, a, false);
	else if (!ft_strncmp(move, "pb", 3))
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
	//free(move);
	if (check_sorted(a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}
