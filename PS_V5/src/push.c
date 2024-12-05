/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:27:48 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 18:47:14 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    push(int **a, int **b)
{
    if (!a || !b)
        quit(a, b, 1);
    b[0] = a[0];
    rotate(a);
    a[last_index(a)] = NULL;
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

