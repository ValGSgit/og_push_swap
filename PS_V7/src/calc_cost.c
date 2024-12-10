#include "push_swap.h"

void	calculate_costs(t_stack *node, int size_a, int size_b)
{
	node->cost_b = node->pos;
	if (node->pos > size_b / 2)
		node->cost_b = (size_b - node->pos) * -1;
	node->cost_a = node->target;
	if (node->target > size_a / 2)
		node->cost_a = (size_a - node->target) * -1;
}

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	size_a = get_stack_size(*stack_a);
	size_b = get_stack_size(*stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		calculate_costs(tmp_b, size_a, size_b);
		tmp_b = tmp_b->next;
	}
}

void	find_cheapest(t_stack *stack_b, int *cheapest, int *cost_a, int *cost_b)
{
	while (stack_b)
	{
		int current_cost = abs(stack_b->cost_a) + abs(stack_b->cost_b);
		if (current_cost < *cheapest)
		{
			*cheapest = current_cost;
			*cost_a = stack_b->cost_a;
			*cost_b = stack_b->cost_b;
		}
		stack_b = stack_b->next;
	}
}

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		cost_a;
	int		cost_b;

	cheapest = INT_MAX;
	cost_a = 0;
	cost_b = 0;
	find_cheapest(*stack_b, &cheapest, &cost_a, &cost_b);
	move(stack_a, stack_b, cost_a, cost_b);
}
