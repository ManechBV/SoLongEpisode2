/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:49:13 by mabenois          #+#    #+#             */
/*   Updated: 2025/10/25 21:03:10 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	i = 0;
	while (ft_is_in_set(s1[i], set) == 0)
		i++;
	if (s1[i] == 0)
		return (ft_strdup(""));
	j = ft_strlen(s1);
	while (ft_is_in_set(s1[j - 1], set) == 0)
		j--;
	result = malloc(sizeof(char) * (j - i + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[i], (j - i + 1));
	return (result);
}
