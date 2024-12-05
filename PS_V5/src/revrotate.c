/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:22:42 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 18:41:29 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void revrot(int **a)
{
    int		*tmp;
	int		i;

	i = last_index(a) - 1;
	tmp = a[i];
	while (a[i] && i - 1 >= 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
}

void	rra(int **stack_a)
{
	revrot(stack_a);
	ft_putstr("rra\n");
}

void	rrb(int **stack_b)
{
	revrot(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(int **stack_b, int **stack_a)
{
	revrot(stack_b);
    revrot(stack_a);
	ft_putstr("rrr\n");
}