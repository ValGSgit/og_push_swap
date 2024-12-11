/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:15:34 by codespace         #+#    #+#             */
/*   Updated: 2024/12/11 09:21:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
	int	middle;
}				t_stack;


static void	ft_insert_int_to_top(t_stack *stack, char c, int number)
{
	int	index;

	index = ft_get_index_of_int(stack, number);
	if (index == -1)
		return ;
	if (index <= stack->size / 2)
	{
		while (stack->stack[0] != number)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != number)
			ft_do_reverse_rotate(stack, c);
	}
}

/**
 * @brief Function used to complete the algorithm.
 * Inserts to top the two numbers in parameters and pushing them to a.
 * 
 * @param stack_a		pointer to the stack a
 * @param stack_b		pointer to the stack b
 * @param first			the first number to push
 * @param second		the second number to push
 */
static void	ft_insert_and_push(t_stack *stack_a, t_stack *stack_b, \
	int first, int second)
{
	ft_insert_int_to_top(stack_b, 'b', first);
	ft_do_pa(stack_a, stack_b);
	ft_insert_int_to_top(stack_b, 'b', second);
	ft_do_pa(stack_a, stack_b);
}

/**
 * @brief Function used to push everything from the stack b, to
 * the stack a.
 * It'll get the two biggest numbers and will push the one that
 * is the closest to the top of stack b first then the second one.
 * 
 * @param stack_a 		pointer to the stack a
 * @param stack_b 		pointer to the stack b
 */
static void	ft_push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	first;
	int	second;
	int	first_index;
	int	second_index;

	while (stack_b->size)
	{
		first = ft_find_max_int(stack_b);
		second = ft_find_next_max_int(stack_b, first);
		first_index = ft_get_index_of_int(stack_b, first);
		second_index = ft_get_index_of_int(stack_b, second);
		if (first_index > stack_b->size / 2)
			first_index = stack_b->size - first_index;
		if (second_index > stack_b->size / 2)
			second_index = stack_b->size - second_index;
		if (first_index < second_index)
			ft_insert_and_push(stack_a, stack_b, first, second);
		else
			ft_insert_and_push(stack_a, stack_b, second, first);
		if (stack_a->stack[0] > stack_a->stack[1])
			ft_do_swap(stack_a, 'a');
	}
}

/**
 * @brief Quick sort algorithm based function, called chunk sort here.
 * It'll creates small stacks of chunk_size integers.
 * 
 * @param stack_a 		pointer to the stack a
 * @param stack_b 		pointer to the stack b
 * @param chunk_size 	the size of a chunk
 */
void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	index;
	int	min_int;
	int	times;

	while (stack_a->size)
	{
		times = 0;
		min_int = ft_find_min_int(stack_a);
		while (times++ < chunk_size)
		{
			min_int = ft_find_next_min_int(stack_a, min_int);
			if (times == chunk_size / 2)
				stack_a->middle = min_int;
		}
		times = 0;
		while (times++ < chunk_size)
		{
			index = ft_get_min_int_index(stack_a, min_int);
			ft_insert_int_to_top(stack_a, 'a', stack_a->stack[index]);
			ft_do_pb(stack_a, stack_b);
			if (stack_b->stack[0] < stack_a->middle)
				ft_do_rotate(stack_b, 'b');
		}
	}
	ft_push_b_to_a(stack_a, stack_b);
}


int	ft_get_index_of_int(t_stack *stack, int number)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == number)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Function used to find the next max int in a stack.
 * 
 * @param stack 		pointer to the stack
 * @param max 			the current max int in the stack
 * @return int 			the next max int found
 */
int	ft_find_next_max_int(t_stack *stack, int max)
{
	int	i;
	int	next_max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next_max = INT_MIN;
	while (i < stack->size)
	{
		if (stack->stack[i] > next_max && stack->stack[i] < max)
			next_max = stack->stack[i];
		i++;
	}
	return (next_max);
}

/**
 * @brief Function used to find the next min int in a stack.
 * 
 * @param stack 		pointer to the stack
 * @param min 			the current min int in the stack
 * @return int 			the next min int found
 */
int	ft_find_next_min_int(t_stack *stack, int min)
{
	int	i;
	int	next_min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next_min = INT_MAX;
	while (i < stack->size)
	{
		if (stack->stack[i] > min && stack->stack[i] < next_min)
			next_min = stack->stack[i];
		i++;
	}
	return (next_min);
}

/**
 * @brief Function used to found the first number's index that
 * is smaller than the min int in a stack.
 * 
 * @param stack 		pointer to the stack
 * @param min 			the current min int in the stack
 * @return int 			the index of the first number smaller than min
 */
int	ft_get_min_int_index(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] <= min)
			break ;
		i++;
	}
	return (i);
}

static void	ft_sort_two(t_stack *stack)
{
	if (ft_is_sorted(stack))
		return ;
	if (stack->stack[0] > stack->stack[1])
		ft_do_rotate(stack, 'a');
}

/**
 * @brief Simple brute forced algorithm for three numbers
 * 
 * @param stack 		pointer to the stack
 */
static void	ft_sort_three(t_stack *stack)
{
	if (ft_is_sorted(stack))
		return ;
	if (stack->stack[0] > stack->stack[1])
	{
		if (stack->stack[1] < stack->stack[stack->size - 1]
			&& stack->stack[stack->size - 1] < stack->stack[0])
			ft_do_rotate(stack, 'a');
		else
			ft_do_swap(stack, 'a');
	}
	if (stack->stack[stack->size - 1] < stack->stack[0]
		&& stack->stack[0] < stack->stack[1])
		ft_do_reverse_rotate(stack, 'a');
	if (stack->stack[0] < stack->stack[stack->size - 1]
		&& stack->stack[stack->size - 1] < stack->stack[1])
	{
		ft_do_swap(stack, 'a');
		ft_sort_three(stack);
	}
}

/**
 * @brief Simple brute forced algorithm for four or five numbers
 * 
 * @param stack_a 			pointer to the stack a
 * @param stack_b 			pointer to the stack b
 */
static void	ft_sort_four_and_five(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	if (stack_a->size == 4)
	{
		ft_insert_min_int_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
		if (!ft_is_sorted(stack_a))
			ft_sort_three(stack_a);
		ft_do_pa(stack_a, stack_b);
	}
	else
	{
		ft_insert_min_int_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
		ft_insert_min_int_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
		if (!ft_is_sorted(stack_a))
			ft_sort_three(stack_a);
		ft_do_pa(stack_a, stack_b);
		ft_do_pa(stack_a, stack_b);
	}
}

/**
 * @brief Function used to initialize the sorting algorithms.
 * It'll find the best algorithm to start depending on the size
 * of the stack a.
 * 
 * @param stack_a 			pointer to the stack a
 * @param stack_b 			pointer to the stack b
 */
void	ft_init_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->size == 2)
		ft_sort_two(stack_a);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size <= 5)
		ft_sort_four_and_five(stack_a, stack_b);
	else if (stack_a->size <= 120)
		ft_chunk_sort(stack_a, stack_b, 18);
	else
		ft_chunk_sort(stack_a, stack_b, 50);
	ft_print_instruction("");
}

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}


int	ft_find_min_int(t_stack *stack)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	min = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	ft_find_max_int(t_stack *stack)
{
	int	i;
	int	max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	max = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}


void	ft_insert_min_int_to_top(t_stack *stack, char c)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return ;
	i = 0;
	min = ft_find_min_int(stack);
	while (stack->stack[i] != min)
		i++;
	if (i <= stack->size / 2)
	{
		while (stack->stack[0] != min)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != min)
			ft_do_reverse_rotate(stack, c);
	}
}

void	ft_insert_max_int_to_top(t_stack *stack, char c)
{
	int	i;
	int	max;

	if (!stack || !stack->stack)
		return ;
	i = 0;
	max = ft_find_max_int(stack);
	while (stack->stack[i] != max)
		i++;
	if (i <= stack->size / 2)
	{
		while (stack->stack[0] != max)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != max)
			ft_do_reverse_rotate(stack, c);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;

	if (argc == 1)
		return (1);
	if (argc < 1)
		ft_error(NULL, NULL, NULL);
	ft_check_args(argc, argv);
	stack_a = ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (1);
	splitted = ft_process_args(argc, argv, stack_a);
	stack_a->stack = ft_parse_args(splitted, stack_a);
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		ft_error(splitted, stack_a, stack_a->stack);
	stack_b->stack = ft_calloc(stack_a->size + 1, sizeof(int));
	if (!stack_b->stack)
		return (1);
	stack_b->size = 0;
	if (!ft_is_sorted(stack_a))
		ft_init_sort(stack_a, stack_b);
	ft_free_all_stacks(stack_a, stack_b);
	return (0);
}