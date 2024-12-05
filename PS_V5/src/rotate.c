/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:57:51 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 15:35:45 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(int **a)
{
    int		*tmp;
	int		i;

	i = 1;
	tmp = a[0];
	while (a[i] && i < last_index(a))
	{
		a[i - 1] = a[i];
		i++;
	}
	a[i - 1] = tmp;
}

void	rb(int **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	ra(int **stack_b)
{
	rotate(stack_b);
	ft_putstr("ra\n");
}

void	rr(int **stack_b, int **stack_a)
{
	rotate(stack_b);
    rotate(stack_a);
	ft_putstr("rr\n");
}