/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:27:09 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/26 19:19:09 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	size;

	size = 0;
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

static void	ft_fill_res(char **res, int n, int size, int is_neg)
{
	int	i;

	i = size - 1;
	if (n == 0)
	{
		(*res)[0] = '0';
	}
	else
	{
		while (i > is_neg - 1)
		{
			(*res)[i] = (n % 10) + '0';
			n /= 10;
			i--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		is_neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = 0;
	if (n < 0)
	{
		is_neg++;
		n *= -1;
	}
	size = ft_intlen(n) + is_neg;
	res = ft_calloc(sizeof(char), (size + 1));
	if (!res)
		return (NULL);
	if (is_neg == 1)
		res[0] = '-';
	ft_fill_res(&res, n, size, is_neg);
	res[size] = '\0';
	return (res);
}
