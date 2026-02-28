/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:42:12 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 08:37:37 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

static void	get_offset(t_vars *vars, int *dx, int *dy)
{
	int			x;
	int			y;

	y = -1;
	while (++y < vars->map->h)
	{
		x = -1;
		while (++x < vars->map->w)
		{
			if (vars->map->map[y][x] == P)
			{
				*dx = 400 - x * 60;
				*dy = 400 - y * 60;
				return ;
			}
		}
	}
}

static void	draw_frame(t_vars *vars, int i, int x, int y)
{
	mlx_color	pix[60 * 60];
	int			ox;
	int			oy;

	ox = 0;
	oy = 0;
	get_offset(vars, &ox, &oy);
	mlx_get_image_region(vars->mlx_vars->mlx, vars->imgs->tileset,
			i * 60, 0, 60, 60, pix);
	mlx_pixel_put_region(vars->mlx_vars->mlx,
			vars->mlx_vars->win, ox + (x * 60), oy + (y * 60),
			60, 60, pix);
}

void	ft_draw_map(t_vars *vars)
{
	int			x;
	int			y;

	y = -1;
	while (++y < vars->map->h)
	{
		x = -1;
		while (++x < vars->map->w)
		{
			draw_frame(vars, vars->map->map[y][x], x, y);
			if (vars->map->map[y][x] == C)
				draw_frame(vars, 6 + vars->timers->coin_frame, x, y);
		}
	}
}
