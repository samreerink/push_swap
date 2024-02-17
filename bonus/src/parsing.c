/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   parsing.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/15 15:47:33 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/17 19:24:14 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	split_arguments(int argc, char *argv[], t_stack **stack)
{
	size_t	i;
	size_t	j;
	char	**temp;

	i = 1;
	j = 0;
	if (!check_digits(argv))
		return (false);
	(*stack)->split_args = malloc(argc * sizeof(char **));
	if (!(*stack)->split_args)
		return (false);
	while (argv[i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return (false);
		(*stack)->split_args[j] = temp;
		i++;
		j++;
	}
	(*stack)->split_args[j] = NULL;
	return (true);
}
