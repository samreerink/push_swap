/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   atoi_overflow.c                                   :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/15 15:31:30 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/15 15:31:32 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	atoi_overflow(const char *str, int *nb)
{
	int	i;
	int	multi;

	i = 0;
	*nb = 0;
	multi = 1;
	if (str[i] == '-')
	{
		multi = -1;
		i++;
	}
	while (str[i])
	{
		*nb += str[i] - '0';
		if (*nb < 0 && (multi == 1 || *nb != INT_MIN))
			return (false);
		if (str[i + 1])
			*nb *= 10;
		i++;
	}
	*nb *= multi;
	return (true);
}
