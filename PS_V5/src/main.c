/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:57:48 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 18:45:52 by vagarcia         ###   ########.fr       */
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

void    *init_stack(int amount, int **b)
{
    int i;

    if (!b)
    {
        b = ft_calloc(sizeof(int *), amount + 1);
        if (!b)
            return (free_stack(b), NULL);
    }
    i = 0;
    while (i < amount)
    {
        b[i] = NULL;
        i++;
    }
    return (b);
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
        stack_b = init_stack(ac, stack_b);
        print_stack(stack_a, stack_b);
        //if (!stack_b || !stack_a)
        //   quit(stack_a, stack_b, 1);
        //rra(stack_a);
        //ra(stack_a);
        pa(stack_a, stack_b);
        //sa(stack_a);
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
