#include "push_swap.h"

void init_stack(t_stack *stack, int size)
{
    stack->data = (int *)malloc(sizeof(int) * size);
    if (!stack->data)
    {
        perror("Error allocating memory for stack");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
}

void free_stack(t_stack *stack)
{
    if (stack->data)
        free(stack->data);
}

void print_stack(t_stack *a, t_stack *b)
{
    int i;

    i = a->top;
    printf("Stack A: ");
    while (i >= 0)
        printf("%d ", a->data[i--]);
    printf("\n");

    i = b->top;
    printf("Stack B: ");
    while (i >= 0)
        printf("%d ", b->data[i--]);
    printf("\n");
}

void quit(t_stack *a, t_stack *b, int code)
{
    free_stack(a);
    free_stack(b);
    exit(code);
}