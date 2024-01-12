/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   push_swap.h                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/12 14:34:14 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/12 15:03:35 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		n;
	struct s_stack	*next;
}	t_stack;

#endif
