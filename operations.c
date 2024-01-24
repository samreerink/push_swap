/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   operations.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/24 16:37:55 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/24 18:10:30 by sreerink      ########   odam.nl         */
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
	write(1, "sa\n", 3);
}

void	rotate(t_node **head, t_node **last)
{
	t_node	*temp;

	temp = (*head)->next;
	(*last)->next = *head;
	*last = *head;
	(*last)->next = NULL;
	*head = temp;
	write(1, "ra\n", 3);
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
	write(1, "rra\n", 4);
}
