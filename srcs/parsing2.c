/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 00:07:29 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 05:06:14 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "vars.h"

void	free_vars(t_vars *vars)
{
	int	i;

	if (!vars)
		return ;
	i = -1;
	if (vars->map)
		while (++i < vars->map->h)
			if (vars->map->map[i] != NULL)
				free(vars->map->map[i]);
	free(vars->map->map);
	free(vars->map);
}

int	ft_error_free_map(t_map *map, int y, char *tmp, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (y >= 0)
		free(map->map[y--]);
	free(map->map);
	free(tmp);
	close(fd);
	return (ft_error("The map must be rectangular."));
}

int	ft_check_line_w(char *tmp, size_t map_w)
{
	if (ft_strlen(tmp) > 0)
	{
		if (tmp[ft_strlen(tmp) - 1] == '\n')
		{
			if ((ft_strlen(tmp) - 1) == map_w)
				return (0);
		}
		else
			if (ft_strlen(tmp) == map_w)
				return (0);
	}
	return (-1);
}

static int	map_occ(t_map *map, int val)
{
	int	x;
	int	y;
	int	occ;

	occ = 0;
	y = -1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
			if (map->map[y][x] == val)
				occ++;
	}
	return (occ);
}

int	ft_check_border(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
		{
			if (x == 0 && map->map[y][x] != 1)
				return (ft_error("Map need to be closed!"));
			if (x == (map->w - 1) && map->map[y][x] != 1)
				return (ft_error("Map need to be closed!"));
			if (y == 0 && map->map[y][x] != 1)
				return (ft_error("Map need to be closed!"));
			if (y == (map->h - 1) && map->map[y][x] != 1)
				return (ft_error("Map need to be closed!"));
		}
	}
	if (map_occ(map, C) < 1 || map_occ(map, P) != 1)
		return (ft_error("Wrong number of C or P."));
	if (map_occ(map, E) != 1)
		return (ft_error("Wrong number of E."));
	return (0);
}
