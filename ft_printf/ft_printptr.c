/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:15:56 by mabenois          #+#    #+#             */
/*   Updated: 2025/11/05 19:27:25 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

static void	ft_putnbr(unsigned long nb, int *i, char *base)
{
	if (nb >= 16)
	{
		ft_putnbr(nb / 16, i, base);
		ft_putnbr(nb % 16, i, base);
	}
	else if (nb <= 16)
		ft_putchar(base[nb % 16], i);
}

int	ft_printptr(void *ptr)
{
	int				ret;
	unsigned long	a;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ret = 0;
	a = (unsigned long) ptr;
	ft_putstr_fd("0x", 1);
	ft_putnbr(a, &ret, "0123456789abcdef");
	return (ret + 2);
}
