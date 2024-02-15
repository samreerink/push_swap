/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   checks.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/15 15:43:06 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/15 16:13:15 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sorted(t_stack **stack)
{
	t_node	*current;
	size_t	i;

	i = 0;
	current = (*stack)->head;
	while (current->index == i)
	{
		if (!current->next)
			return (true);
		current = current->next;
		i++;
	}
	return (false);
}

bool	check_duplicate(t_stack **stack)
{
	t_node	*current;
	t_node	*to_check;

	current = (*stack)->head;
	while (current)
	{
		to_check = (*stack)->head;
		while (to_check)
		{
			if ((current->index == to_check->index) && (current != to_check))
				return (false);
			to_check = to_check->next;
		}
		current = current->next;
	}
	return (true);
}

bool	check_digits(char *argv[])
{
	size_t	i;
	size_t	j;
	int		c;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			c = argv[i][j];
			if ((c < 48 || c > 57) && (c != 32 && c != 45))
				return (false);
			if (c == 45 && (argv[i][j + 1] == 45 || !argv[i][j + 1]))
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}
