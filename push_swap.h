/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   push_swap.h                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/12 14:34:14 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/22 22:56:05 by sreerink      ########   odam.nl         */
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
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*last;
	char	***split_args;
}	t_stack;

#endif
