/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   operations.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/24 16:37:55 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/28 16:59:31 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_node **head)
{
	t_node	*temp;

	if (!*head || !(*head)->next)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
}

void	push(t_node **head_one, t_node **head_two)
{
	t_node	*temp;

	if (!*head_one)
		return ;
	temp = *head_one;
	*head_one = (*head_one)->next;
	temp->next = *head_two;
	*head_two = temp;
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
