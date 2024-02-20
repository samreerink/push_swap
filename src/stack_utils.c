/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   stack_utils.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/15 15:26:15 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/19 23:11:33 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	stack_length(t_stack **stack)
{
	t_node	*current;
	size_t	length;

	length = 0;
	current = (*stack)->head;
	while (current)
	{
		length++;
		current = current->next;
	}
	return (length);
}

bool	index_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*to_check;
	size_t	index;

	index = 0;
	current = (*stack)->head;
	while (current)
	{
		to_check = (*stack)->head;
		while (to_check)
		{
			if (current->n > to_check->n)
				index++;
			to_check = to_check->next;
		}
		current->index = index;
		current = current->next;
		index = 0;
	}
	return (check_duplicate(stack));
}
