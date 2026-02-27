/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:59:13 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/06 23:55:06 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	while (ft_isspace(nptr[i]) != 0)
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(nptr[i]) != 0)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
