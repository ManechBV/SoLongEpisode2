/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:46:53 by mabenois          #+#    #+#             */
/*   Updated: 2025/10/16 21:02:40 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occ;

	last_occ = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_occ = (char *)(&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		last_occ = (char *)(&s[i]);
	return (last_occ);
}
