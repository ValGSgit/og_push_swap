#include "push_swap.h"

void sa(t_stack *a)
{
    if (a->top > 0)
    {
        int temp = a->data[a->top];
        a->data[a->top] = a->data[a->top - 1];
        a->data[a->top - 1] = temp;
        write(1, "sa\n", 3);
    }
}

void sb(t_stack *b)
{
    if (b->top > 0)
    {
        int temp = b->data[b->top];
        b->data[b->top] = b->data[b->top - 1];
        b->data[b->top - 1] = temp;
        write(1, "sb\n", 3);
    }
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}

void pa(t_stack *a, t_stack *b)
{
    if (b->top >= 0)
    {
        a->data[++a->top] = b->data[b->top--];
        write(1, "pa\n", 3);
    }
}

void pb(t_stack *a, t_stack *b)
{
    if (a->top >= 0)
    {
        b->data[++b->top] = a->data[a->top--];
        write(1, "pb\n", 3);
    }
}

void ra(t_stack *a)
{
    if (a->top > 0)
    {
        int temp = a->data[a->top];
        for (int i = a->top; i > 0; i--)
            a->data[i] = a->data[i - 1];
        a->data[0] = temp;
        write(1, "ra\n", 3);
    }
}

void rb(t_stack *b)
{
    if (b->top > 0)
    {
        int temp = b->data[b->top];
        for (int i = b->top; i > 0; i--)
            b->data[i] = b->data[i - 1];
        b->data[0] = temp;
        write(1, "rb\n", 3);
    }
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}

void rra(t_stack *a)
{
    if (a->top > 0)
    {
        int temp = a->data[0];
        for (int i = 0; i < a->top; i++)
            a->data[i] = a->data[i + 1];
        a->data[a->top] = temp;
        write(1, "rra\n", 4);
    }
}

void rrb(t_stack *b)
{
    if (b->top > 0)
    {
        int temp = b->data[0];
        for (int i = 0; i < b->top; i++)
            b->data[i] = b->data[i + 1];
        b->data[b->top] = temp;
        write(1, "rrb\n", 4);
    }
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}