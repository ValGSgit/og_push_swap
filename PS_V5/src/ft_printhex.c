/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:34:17 by vagarcia          #+#    #+#             */
/*   Updated: 2024/11/27 15:29:13 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			else if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, format);
	return (ft_hexlen(num));
}

size_t	intputnbr(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
	{
		ft_printstr("-2147483648");
		len = 11;
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		len += intputnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	if (n < 10)
		len += ft_putchar(n % 10 + '0');
	return (len);
}