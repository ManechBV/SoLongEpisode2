/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:03:40 by mabenois          #+#    #+#             */
/*   Updated: 2025/11/05 19:26:53 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

static void	ft_putnbr(unsigned int nb, int *i, char *base)
{
	if (nb >= 16)
	{
		ft_putnbr(nb / 16, i, base);
		ft_putnbr(nb % 16, i, base);
	}
	else if (nb <= 16)
		ft_putchar(base[nb % 16], i);
}

int	ft_printhex(unsigned int a, int is_upper)
{
	int	ret;

	ret = 0;
	if (is_upper == 0)
		ft_putnbr(a, &ret, "0123456789abcdef");
	else
		ft_putnbr(a, &ret, "0123456789ABCDEF");
	return (ret);
}
