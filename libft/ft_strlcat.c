/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:10 by mabenois          #+#    #+#             */
/*   Updated: 2025/10/27 16:24:11 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && j < n - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldest;
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (size == 0)
		return (lsrc);
	ldest = ft_strlen(dst);
	if (size <= ldest)
		return (size + lsrc);
	ft_strncat(dst, src, size - ldest);
	return (ldest + lsrc);
}
