/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/12 14:34:24 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/12 16:58:16 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *msg)
{
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	check_input(char *argv[])
{
	int	check;
	size_t	i;
	size_t	j;

	i = 1;
	check = 1;
	while (argv[i] && check)
	{
		j = 0;
		while (argv[i][j] && check)
		{
			check = ft_isdigit(argv[i][j]);
			j++;
		}
		i++;
	}
	return (check);
}

int	main(int argc, char *argv[])
{
	size_t	i;
	t_stack	*a_head;
	t_stack	*a_last;
	t_stack	*b_head;
	t_stack	*b_last;

	if (argc < 2)
		error_exit("Invalid amount of arguments\n");
	if (!check_input(argv))
		error_exit("Input is not digit only\n");
	return (EXIT_SUCCESS);
}
