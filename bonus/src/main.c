/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/02/16 23:10:53 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/17 01:58:12 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (EXIT_SUCCESS);
	init_stack(&stack_a);
	if (!stack_a)
		error_exit(NULL, NULL);
	init_stack(&stack_b);
	if (!stack_b)
		error_exit(&stack_a, NULL);
	if (!split_arguments(argc, argv, &stack_a))
		error_exit(&stack_a, &stack_b);
	if (!make_stack(&stack_a))
		error_exit(&stack_a, &stack_b);
	if (!index_stack(&stack_a))
		error_exit(&stack_a, &stack_b);
	checker(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}
