/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:04:33 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/27 02:21:19 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vars.h"
#include "get_next_line.h"

static int	read_map_wh(int fd, int *w)
{
	int		h;
	char	*tmp;

	h = 0;
	tmp = get_next_line(fd);
	if (tmp)
	{
		*w = ft_strlen(tmp);
		if (*w > 0)
			if (tmp[*w - 1] == '\n')
				*w = *w - 1;
	}
	while (tmp)
	{
		h++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (h);
}

static int	ft_convert_chr(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'P')
		return (P);
	else if (c == 'C')
		return (C);
	else if (c == 'E')
		return (E);
	else
		return (-1);
}

static int	ft_convert_map(char *filename, t_map *map)
{
	int		fd;
	char	*tmp;
	int		y;
	int		x;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("map can't be opened."));
	tmp = get_next_line(fd);
	y = -1;
	while (tmp)
	{
		map->map[++y] = malloc(sizeof(int) * map->w);
		if (!map->map[y])
			return (ft_error_free_map(map, y, tmp, fd));
		if (ft_check_line_w(tmp, (size_t) map->w) == -1)
			return (ft_error_free_map(map, y, tmp, fd));
		x = -1;
		while (++x < map->w)
			map->map[y][x] = ft_convert_chr(tmp[x]);
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static t_map	*ft_new_map(int fd, char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->w = 0;
	map->h = read_map_wh(fd, &map->w);
	if (map->w == 0 || map->h == 0)
	{
		free(map);
		return (NULL);
	}
	map->map = malloc(sizeof(int*) * map->h);
	if (!map->map)
	{
		free(map);
		return (NULL);
	}
	if (ft_convert_map(filename, map) == -1)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

int	read_and_parse(t_vars *vars, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("map can't be opened."));
	vars->map = ft_new_map(fd, filename);
	if (!vars->map)
		return (-1);
	//if (ft_check_map_flood(vars->map) == -1)
	//	return (-1);
	return (0);
}
