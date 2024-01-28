/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   push_swap.h                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/12 14:34:14 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/28 20:37:53 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_node
{
	int		n;
	size_t		index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*last;
	char	***split_args;
}	t_stack;

void	swap_first_two(t_node **head);

void	push(t_node **head_one, t_node **head_two);

void	rotate(t_node **head, t_node **last);

void	reverse_rotate(t_node **head, t_node **last);

#endif
