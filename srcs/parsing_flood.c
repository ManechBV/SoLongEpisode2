/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flood.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 04:07:36 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 04:50:49 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "vars.h"

static int	free_flood_map(int **map, int y, int ret)
{
	while (y >= 0)
		if (map[y])
			free(map[y--]);
	free(map);
	return (ret);
}

static int	map_occ(t_map *map, int **fld, int val)
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
			if (fld[y][x] == val)
				occ++;
	}
	return (occ);
}

static void	will_flood(int **fld, int x, int y, int *chng)
{
	int	put_water;

	put_water = 0;
	if (fld[y][x] == 0 || fld[y][x] == C || fld[y][x] == E)
	{
		if (fld[y - 1][x] == P || fld[y - 1][x] == 6)
			put_water = 1;
		if (fld[y + 1][x] == P || fld[y + 1][x] == 6)
			put_water = 1;
		if (fld[y][x - 1] == P || fld[y][x - 1] == 6)
			put_water = 1;
		if (fld[y][x + 1] == P || fld[y][x + 1] == 6)
			put_water = 1;
		if (put_water == 1)
		{
			fld[y][x] = 6;
			(*chng)++;
		}
	}
}

static int	ft_flood_map(t_map *map, int **fld)
{
	int	x;
	int	y;
	int	change;

	change = 1;
	while ((map_occ(map, fld, 0) + map_occ(map, fld, C)) > 0)
	{
		if (change > 0)
			change = 0;
		else
			return (free_flood_map(fld, map->h - 1, -1));
		y = 0;
		while (++y < map->h - 1)
		{
			x = 0;
			while (++x < map->w - 1)
			{
				will_flood(fld, x, y, &change);
				if (map->map[y][x] == E && map_occ(map, fld, C) == 0)
					if (fld[y][x] == 6)
						return (free_flood_map(fld, map->h - 1, 0));
			}
		}
	}
	return (free_flood_map(fld, map->h - 1, -1));
}

int	ft_check_map_flood(t_map *map)
{
	int	**flood_map;
	int	x;
	int	y;

	flood_map = malloc(sizeof(int *) * map->h);
	if (!flood_map)
		return (-1);
	y = -1;
	while (++y < map->h)
	{
		flood_map[y] = malloc(sizeof(int) * map->w);
		if (!flood_map[y])
			return (free_flood_map(flood_map, y, -1));
		x = -1;
		while (++x < map->w)
		{
			if (map->map[y][x] >= 0 && map->map[y][x] <= 4)
				flood_map[y][x] = map->map[y][x];
			else
				return (free_flood_map(flood_map, y, -1));
		}
	}
	if (ft_flood_map(map, flood_map) == -1)
		return (ft_error("Need valid path."));
	return (0);
}
