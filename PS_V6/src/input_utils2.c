#include "push_swap.h"

int	ft_skipspace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	neg;
	long int	res;

	i = ft_skipspace(str);
	res = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
    {
		res *= 10;
		res += (int)(str[i] - 48);
		i++;
	}
	return (neg * res);
}