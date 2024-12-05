/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:29 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/05 17:17:45 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t	i;
	size_t	typ;

	typ = nmemb * size;
	if (size && ((typ / size) != nmemb))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (free(ptr), NULL);
	i = 0;
	while (i < typ)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

int	**put_in_stack(char **av, int ac)
{
	int			i;
	int			**a;
    
	i = 0;
	a = ft_calloc(ac + 1, sizeof(int *));
	if (!a)
		return (free_stack(a), free_input(av), NULL);
	while (i < ac)
	{
		a[i] = (int *)ft_atoi(av[i]);
		i++;
	}
	free_input(av);
	av = NULL;
    return (a);
}
