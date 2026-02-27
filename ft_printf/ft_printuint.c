/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:56:53 by mabenois          #+#    #+#             */
/*   Updated: 2025/11/05 19:29:58 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

static void	ft_putnbr(unsigned int nb, int *i)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, i);
		ft_putnbr(nb % 10, i);
	}
	else if (nb < 10)
		ft_putchar(nb + '0', i);
}

int	ft_printuint(unsigned int a)
{
	int	ret;

	ret = 0;
	ft_putnbr(a, &ret);
	return (ret);
}
