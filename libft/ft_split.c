/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:36:33 by mabenois          #+#    #+#             */
/*   Updated: 2025/10/25 20:34:26 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_next_word(unsigned int *i, char const *s, char c)
{
	unsigned int	start;
	size_t			size;
	char			*word;

	if (*i != 0)
	{
		while (s[*i] != c && s[*i] != '\0')
			(*i)++;
	}
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	start = *i;
	size = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		size++;
		(*i)++;
	}
	word = ft_substr(s, start, size);
	if (!word)
		return (NULL);
	return (word);
}

static int	ft_get_tab_size(char const *s, char c)
{
	unsigned int	i;
	size_t			size;
	char			*word;

	i = 0;
	size = 0;
	word = NULL;
	while (s[i] != '\0')
	{
		word = ft_get_next_word(&i, s, c);
		if (word == NULL)
		{
			free(word);
			return (-1);
		}
		if (word[0] != '\0')
			size++;
		free(word);
		word = NULL;
	}
	if (word != NULL)
		free(word);
	return (size);
}

static void	ft_free_tab_on_error(char **tab, unsigned int tab_i)
{
	unsigned int	i;

	i = 0;
	while (i < tab_i)
		free(tab[i++]);
	free(tab);
}

static char	**ft_split_into_tab(char const *s, char c, unsigned int i)
{
	int				tab_size;
	char			**tab;
	unsigned int	tab_i;

	tab_i = 0;
	if (s == NULL)
		return (NULL);
	tab_size = ft_get_tab_size(s, c);
	if (tab_size == -1)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	if (!tab)
		return (NULL);
	while (tab_i < (unsigned int)tab_size)
	{
		tab[tab_i] = ft_get_next_word(&i, s, c);
		if (tab[tab_i] == NULL)
		{
			ft_free_tab_on_error(tab, tab_i);
			return (NULL);
		}
		tab_i++;
	}
	tab[tab_i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;

	tab = ft_split_into_tab(s, c, 0);
	if (!tab)
		return (NULL);
	return (tab);
}
