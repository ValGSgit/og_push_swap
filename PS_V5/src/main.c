/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:57:48 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/09 12:49:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(int **a, int **b)
{
    int i;
    int f;
    int k;

    i = 0;
    f = 0;
    k = 1;
    if (!a || !b)
        ft_printf("stack doesnt exist when it gets here...");
    while (a[i])
        ft_printf("%d: %d | %d\n", k++, a[i++], b[f++]);
}

void    *init_stack(int amount, int ***b)
{
    int i;

    if (!*b)
    {
        *b = ft_calloc(amount + 1, sizeof(int *));
        if (!*b)
            return (free_stack(*b), NULL);
    }
    i = 0;
    while (i < amount)
    {
        (*b)[i] = ft_calloc(1, sizeof(int));
        if (!(*b)[i])
            return (free_stack(*b), NULL);
        i++;
    }
    (*b)[i] = NULL;
    return (*b);
}

int main(int ac, char **av)
{
    int **stack_a;
    int **stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        quit(stack_a, stack_b, 1);
    av = splitavs(ac, av);
    ac = argcount(av);
    if (!av || !*av || check(av) == 0)
        return (free_input(av), quit(stack_a, stack_b, 1), 1);
    else
    {
        stack_a = put_in_stack(av, ac);
        print_stack(stack_a, stack_b);
        if (!init_stack(ac, &stack_b))
            quit(stack_a, stack_b, 1);
        pa(stack_a, stack_b);
        print_stack(stack_a, stack_b);
    }
    if (sorted(stack_a, stack_b) == 1)
        ft_printf("not sorted\n");
    print_stack(stack_a, stack_b);
    ft_printf("starts sorting...\n");
    free(stack_a);
    free(stack_b);
    return (0);
}
