/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   small_sort_utils.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/13 17:02:44 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/13 19:50:17 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_index_count(t_stack **stack, size_t index)
{
	t_node	*current;
	size_t	count;

	count = 0;
	current = (*stack)->head;
	while (current->index != index)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	update_index(t_stack **stack)
{
	t_node	*current;

	current = (*stack)->head;
	while (current)
	{
		current->index--;
		current = current->next;
	}
}

void	smallest_to_top(t_stack **stack, size_t count, size_t len)
{
	while (count > 0 && count < 3)
	{
		move_ra(stack, true);
		count--;
	}
	if (count >= 3)
	{
		move_rra(stack, true);
		if (count == 3 && len == 5)
			move_rra(stack, true);
	}
}
