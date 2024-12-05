/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:57:49 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 14:57:00 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    swap(int **a)
{
    int tmp;

    tmp = *a[1];
    a[1] = a[0];
    *a[0] = tmp;
}

void	sb(int **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	sa(int **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	ss(int **stack_b, int **stack_a)
{
	swap(stack_b);
    swap(stack_a);
	ft_putstr("ss\n");
}

void    ft_putstr(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}