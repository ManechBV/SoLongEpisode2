/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:06:10 by mabenois          #+#    #+#             */
/*   Updated: 2025/10/24 18:57:47 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	start;
	size_t	increment;

	if (dest == ((void *)0) && src == ((void *)0))
		return (NULL);
	i = 0;
	increment = 1;
	start = 0;
	if (src < dest)
	{
		increment = -1;
		start = n - 1;
	}
	while (i < n)
	{
		((unsigned char *)dest)[start] = ((unsigned char *)src)[start];
		start += increment;
		i++;
	}
	return (dest);
}
