/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   stack_init.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/15 15:26:33 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/19 23:14:03 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	init_stack(t_stack **new_stack)
{
	*new_stack = malloc(sizeof(t_stack));
	if (!*new_stack)
		return ;
	(*new_stack)->head = NULL;
	(*new_stack)->last = NULL;
	(*new_stack)->split_args = NULL;
}

t_node	*make_node(char *str_nb, t_node *last)
{
	t_node	*new_node;

	if (!str_nb)
		return (NULL);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	if (!atoi_overflow(str_nb, &new_node->n))
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	if (last != NULL)
		last->next = new_node;
	return (new_node);
}

bool	make_stack(t_stack **stack)
{
	size_t	i;
	size_t	j;
	char	***split_args;

	i = 0;
	j = 1;
	split_args = (*stack)->split_args;
	(*stack)->head = make_node(split_args[0][0], NULL);
	if (!(*stack)->head)
		return (false);
	(*stack)->last = (*stack)->head;
	while (split_args[i])
	{
		while (split_args[i][j])
		{
			(*stack)->last = make_node(split_args[i][j], (*stack)->last);
			if (!(*stack)->last)
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}
