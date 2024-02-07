/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   radix_sort.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/06 14:37:16 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/07 18:37:31 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	binary_length(size_t nb)
{
	size_t	length;

	length = 0;
	while (nb > 0)
	{
		nb >>= 1;
		length++;
	}
	return (length);
}

void	radix_sort(t_stack **a, t_stack **b, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	max_bits;

	i = 0;
	max_bits = binary_length(len - 1);
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if (((*a)->head->index >> i) & 1)
				move_ra(a, true);
			else
				move_pb(a, b, true);
			j++;
		}
		while ((*b)->head)
			move_pa(b, a, true);
		i++;
	}
}
