/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/12 14:34:24 by sreerink      #+#    #+#                 */
/*   Updated: 2024/01/26 20:02:24 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	// free stacks
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

t_node	*make_node(char *number, t_node *last)
{
	t_node	*new_node;

	if (!number)
		return (NULL);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->n = ft_atoi(number);
	new_node->next = NULL;
	if (last != NULL)
		last->next = new_node;
	return (new_node);
}

bool	check_digits(char *argv[])
{
	size_t	i;
	size_t	j;
	int	c;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			c = argv[i][j];
			//printf("%c (check_digits)\n", argv[i][j]);
			if ((c < 48 || c > 57) && c != 32)
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

bool	split_arguments(char *argv[], t_stack **stack)
{
	size_t	i;
	size_t	j;
	char	**temp;

	i = 1;
	j = 0;
	if (!check_digits(argv))
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

bool	make_stack(t_stack **stack)
{
	size_t	i;
	size_t	j;
	char	***split_args;

	i = 0;
	j = 1;
	split_args = (*stack)->split_args;
	(*stack)->head = make_node(split_args[0][0], NULL);
	if (!(*stack)->head)
		return (false);
	(*stack)->last = (*stack)->head;
	while (split_args[i])
	{
		while (split_args[i][j])
		{
			(*stack)->last = make_node(split_args[i][j], (*stack)->last);
			if (!(*stack)->last)
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

void	init_stack(t_stack **new_stack)
{
	*new_stack = malloc(sizeof(t_stack));
	if (!*new_stack)
		return;
	(*new_stack)->head = NULL;
	(*new_stack)->last = NULL;
	(*new_stack)->split_args = malloc(sizeof(char ***));
	// implement malloc check
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*print_node; // Only for testing purpose
	char	c;

	if (argc <= 1)
		error_exit(NULL, NULL);
	init_stack(&stack_a);
	if (!stack_a)
		error_exit(NULL, NULL);
	init_stack(&stack_b);
	if (!stack_b)
		error_exit(stack_a, NULL);
	if (!split_arguments(argv, &stack_a))
		error_exit(stack_a, stack_b);
	if (!make_stack(&stack_a))
		error_exit(stack_a, stack_b);
	//swap_first_two(&(stack_a->head));
	//rotate(&(stack_a->head), &(stack_a->last));
	push(&(stack_a->head), &(stack_b->head));
	push(&(stack_a->head), &(stack_b->head));
	reverse_rotate(&(stack_a->head), &(stack_a->last));
	print_node = stack_a->head;
	c = 'a';
	while (print_node)
	{
		printf("%c: %d\n", c, print_node->n);
		print_node = print_node->next;
	}
	print_node = stack_b->head;
	c = 'b';
	while (print_node)
	{
		printf("%c: %d\n", c, print_node->n);
		print_node = print_node->next;
	}
	return (EXIT_SUCCESS);
}
