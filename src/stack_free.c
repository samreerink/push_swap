/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   stack_free.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/15 21:16:46 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/19 23:11:32 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_nodes(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = (stack)->head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

void	free_args(t_stack *stack)
{
	size_t	i;
	size_t	j;
	char	***split_args;

	if (!(stack)->split_args)
		return ;
	i = 0;
	j = 0;
	split_args = (stack)->split_args;
	while (split_args[i])
	{
		while (split_args[i][j])
		{
			free(split_args[i][j]);
			j++;
		}
		free(split_args[i][j]);
		free(split_args[i]);
		i++;
		j = 0;
	}
	free(split_args);
}

void	free_stack(t_stack **stack)
{
	if (!*stack)
		return ;
	free_nodes(*stack);
	free_args(*stack);
	free(*stack);
}
