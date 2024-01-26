/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   operations.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/24 16:37:55 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/25 19:08:35 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_node **head)
{
	t_node	*second;

	second = (*head)->next;
	(*head)->next = second->next;
	second->next = *head;
	*head = second;
}

void	push(t_node **head_one, t_node **head_two)
{
	t_node	*temp;

	temp = (*head_one)->next;
	if (!head_two)
		(*head_one)->next = NULL;
	else
		(*head_one)->next = *head_two;
	*head_two = *head_one;
	*head_one = temp;
}

void	rotate(t_node **head, t_node **last)
{
	t_node	*temp;

	temp = (*head)->next;
	(*last)->next = *head;
	*last = *head;
	(*last)->next = NULL;
	*head = temp;
}

void	reverse_rotate(t_node **head, t_node **last)
{
	t_node	*temp;

	temp = *head;
	while (temp->next != *last)
		temp = temp->next;
	(*last)->next = *head;
	*head = *last;
	*last = temp;
	(*last)->next = NULL;
}
