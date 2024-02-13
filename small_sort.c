/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   small_sort.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/07 19:48:51 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/13 18:00:59 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_node	*current;
	t_node	*second;

	current = (*a)->head;
	second = current->next;
	if ((current->index == 0) && (second->index == 2))
	{
		move_rra(a, true);
		move_sa(a, true);
	}
	else if ((current->index == 2) && (second->index == 1))
	{
		move_ra(a, true);
		move_ra(a, true);
	}
	else if ((current->index == 1) && (second->index == 0))
		move_sa(a, true);
	else if ((current->index == 2) && (second->index == 0))
		move_ra(a, true);
	else if ((current->index == 1) && (second->index == 2))
		move_rra(a, true);
}

void	sort_four(t_stack **a, t_stack **b)
{
	size_t	count;

	count = get_index_count(a, 0);
	smallest_to_top(a, count);
	move_pb(a, b, true);
	update_index(a);
	sort_three(a);
	move_pa(b, a, true);
}

void	sort_five(t_stack **a, t_stack **b)
{
	size_t	count;

	count = get_index_count(a, 0);
	smallest_to_top(a, count);
	move_pb(a, b, true);
	update_index(a);
	sort_four(a, b);
}
