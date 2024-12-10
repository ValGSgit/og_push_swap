#include "push_swap.h"

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushes = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushes++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushes > 3)
	{
		pb(stack_a, stack_b);
		pushes++;
	}
}


static void	sort_stack(t_stack **stack_a)
{
	int	lowest_p;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_p = position_lowest_index(stack_a);
	if (lowest_p > stack_size / 2)
	{
		while (lowest_p < stack_size)
		{
			rra(stack_a);
			lowest_p++;
		}
	}
	else
	{
		while (lowest_p > 0)
		{
			ra(stack_a);
			lowest_p--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_init(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_stack(stack_a);
}