/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:19:59 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 17:05:43 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(int **a, int **b)
{
    int i;

	i = 0;
	if (!a)
		return (quit(a, b, 1), 0);
	while (a[i] && i < last_index(a))
	{
		if (a[i] > a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

//void    mumbo_jumbo_sort(int **a, int **b)
