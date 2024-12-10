/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:27:48 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/09 12:39:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    push(int **src, int **dest)
{
    int i;

    if (!src || !dest || !src[0])
        quit(src, dest, 1);
    // Shift dest elements up
    i = last_index(dest) - 1;
    while (i >= 0)
    {
        dest[i + 1] = dest[i];
        i--;
    }
    // Move the top element from src to dest
    dest[0] = src[0];
    // Shift src elements down
    revrot(src);
}

void	pa(int **stack_a, int **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	pb(int **stack_a, int **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

