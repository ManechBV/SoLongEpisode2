/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:39:26 by mabenois          #+#    #+#             */
/*   Updated: 2025/11/05 19:27:05 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

static void	ft_putnbr(int nb, int *i)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*i = 11;
	}
	else if (nb < 0)
	{
		ft_putchar('-', i);
		ft_putnbr(nb * -1, i);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, i);
		ft_putnbr(nb % 10, i);
	}
	else if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0', i);
}

int	ft_printint(int a)
{
	int	ret;

	ret = 0;
	ft_putnbr(a, &ret);
	return (ret);
}
