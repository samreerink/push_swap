/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/12 14:34:24 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/20 19:29:42 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	// free stacks
	exit(EXIT_FAILURE);
}

t_list	*make_node(char *number, t_list *last)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;
	if (last != NULL)
		last_node->next = new_node;
	return (new_node);
}

void	make_stack(char *argv[], t_stack *stack)
{
	size_t	i;
	size_t	j;
	char	**split_args;

	i = 1;
	j = 1;
	split_args = ft_split(argv[1], ' ');
	if (!split_args)
		return (false);
	stack->head = make_node(split_args[0], NULL);
	if (!stack->head)
		return (false);
	while (argv[i])
	{
		while (split_args[j])
		{
			stack->last = make_node(split_args[j], stack->last);
			j++;
		}
		// free_array(split_args);
		i++;
		j = 0;
		split_args = ft_split(argv[i], ' ');
		if (!split
	}
}

t_stack	*init_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->last = NULL;
	return (new_stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		error_exit("Invalid amount of arguments\n");
	stack_a = init_stack;
	if (!stack_a)
		error_exit(NULL, NULL);
	stack_b = init_stack;
	if (!stack_b)
		error_exit(stack_a, NULL);
	make_stack(argv, &stack_a);
	return (EXIT_SUCCESS);
}
