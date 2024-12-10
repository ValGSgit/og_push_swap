#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (ac < 2)
        return (0);
    stack_a = NULL;
    stack_b = NULL;
    av = splitavs(ac, av);
    ac = argcount(av);
    if (check(av) == 0)
        return (free_input(av), quit(stack_a, stack_b, 1), 1);
    init_stack(stack_b, stack_a->top);
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}