/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:29:42 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 17:01:53 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_index(int **a)
{
	int i;

	if (!a)
		return (free_stack(a), 0);
	i = 0;
	while (a[i])
		i++;
	return (i);
}