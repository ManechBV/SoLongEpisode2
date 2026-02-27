/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:09:22 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/05 21:35:17 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	ft_convert_print(va_list args, char c)
{
	int	ret;

	if (c == '%')
		ret = ft_printchar(c);
	if (c == 'c')
		ret = ft_printchar(va_arg(args, int));
	if (c == 's')
		ret = ft_printstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		ret = ft_printint(va_arg(args, int));
	if (c == 'u')
		ret = ft_printuint(va_arg(args, unsigned int));
	if (c == 'x')
		ret = ft_printhex(va_arg(args, unsigned int), 0);
	if (c == 'X')
		ret = ft_printhex(va_arg(args, unsigned int), 1);
	if (c == 'p')
		ret = ft_printptr(va_arg(args, void *));
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += ft_convert_print(args, format[i]);
		}
		else
			ret += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
