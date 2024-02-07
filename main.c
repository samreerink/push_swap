/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/01/12 14:34:24 by sreerink      #+#    #+#                 */
/*   Updated: 2024/02/07 20:14:00 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	// free stacks
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

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

t_node	*make_node(char *str_nb, t_node *last)
{
	t_node	*new_node;

	if (!str_nb)
		return (NULL);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	if (!atoi_overflow(str_nb, &new_node->n))
		return (NULL);
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
			if ((c < 48 || c > 57) && (c != 32 && c != 45))
				return (false);
			if (c == 45 && argv[i][j + 1] == 45)
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

bool	check_duplicate(t_stack **stack)
{
	t_node	*current;
	t_node	*to_check;

	current = (*stack)->head;
	while (current)
	{
		to_check = (*stack)->head;
		while (to_check)
		{
			if ((current->index == to_check->index) && (current != to_check))
				return (false);
			to_check = to_check->next;
		}
		current = current->next;
	}
	return (true);
}

bool	check_sorted(t_stack **stack)
{
	t_node	*current;
	size_t	i;

	i = 0;
	current = (*stack)->head;
	while (current->index == i)
	{
		if (!current->next)
			return (true);
		current = current->next;
		i++;
	}
	return (false);
}

bool	index_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*to_check;
	size_t	index;

	index = 0;
	current = (*stack)->head;
	while (current)
	{
		to_check = (*stack)->head;
		while (to_check)
		{
			if (current->n > to_check->n)
				index++;
			to_check = to_check->next;
		}
		current->index = index;
		current = current->next;
		index = 0;
	}
	return (check_duplicate(stack));
}

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

size_t	stack_length(t_stack **stack)
{
	t_node	*current;
	size_t	length;

	length = 0;
	current = (*stack)->head;
	while (current)
	{
		length++;
		current = current->next;
	}
	return (length);
}

void	small_sort(t_stack **a, t_stack **b, size_t len)
{
	if (len == 2)
		move_sa(a, true);
	if (len == 3)
		sort_three(a);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	size_t	len;

	len = stack_length(a);
	if (check_sorted(a))
	{
		write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	if (len <= 5)
	{
		small_sort(a, b, len);
		return ;
	}
	radix_sort(a, b, len);
}

void	init_stack(t_stack **new_stack)
{
	*new_stack = malloc(sizeof(t_stack));
	if (!*new_stack)
		return;
	(*new_stack)->head = NULL;
	(*new_stack)->last = NULL;
	(*new_stack)->split_args = NULL;
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
	if (!split_arguments(argc, argv, &stack_a))
		error_exit(stack_a, stack_b);
	if (!make_stack(&stack_a))
		error_exit(stack_a, stack_b);
	if (!index_stack(&stack_a))
		error_exit(stack_a, stack_b);
	sort_stack(&stack_a, &stack_b);
/*	print_node = stack_a->head;
	c = 'a';
	while (print_node)
	{
		printf("%c: %d [%zu]\n", c, print_node->n, print_node->index);
		print_node = print_node->next;
	}
	printf("\n");
	print_node = stack_b->head;
	c = 'b';
	while (print_node)
	{
		printf("%c: %d\n", c, print_node->n);
		print_node = print_node->next;
	}*/
	return (EXIT_SUCCESS);
}
