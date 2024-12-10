/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:29 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/09 12:50:09 by codespace        ###   ########.fr       */
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

int **put_in_stack(char **av, int ac)
{
    int **stack;
    int i;

    stack = ft_calloc(ac + 1, sizeof(int *));
    if (!stack)
        return NULL;
    i = 0;
    while (i < ac)
    {
        stack[i] = ft_calloc(1, sizeof(int));
        if (!stack[i])
            return (free_stack(stack), NULL);
        *stack[i] = ft_atoi(av[i]);
        i++;
    }
    stack[i] = NULL;
    return stack;
}
