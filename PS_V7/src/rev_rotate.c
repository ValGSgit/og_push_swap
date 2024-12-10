#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*new_last;

	last = get_bottom(*stack);
	new_last = before_bottom(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	new_last->next = NULL;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}