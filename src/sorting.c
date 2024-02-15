/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   sorting.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/15 15:21:19 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/15 15:45:00 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a, t_stack **b, size_t len)
{
	if (len == 2)
		move_sa(a, true);
	if (len == 3)
		sort_three(a);
	if (len == 4)
		sort_four(a, b);
	if (len == 5)
		sort_five(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	size_t	len;

	len = stack_length(a);
	if (check_sorted(a))
		return ;
	if (len <= 5)
	{
		small_sort(a, b, len);
		return ;
	}
	radix_sort(a, b, len);
}
