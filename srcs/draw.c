/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:42:12 by mabenois          #+#    #+#             */
/*   Updated: 2026/03/04 00:04:40 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

void	get_offset(t_vars *vars, int *dx, int *dy)
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

	mlx_get_image_region(vars->mlx_vars->mlx, vars->imgs->tileset,
		i * 60, 0, 60, 60, pix);
	mlx_pixel_put_region(vars->mlx_vars->mlx,
		vars->mlx_vars->target_win, (x * 60), (y * 60),
		60, 60, pix);
}

void	ft_draw_map(t_vars *vars)
{
	int			x;
	int			y;
	float		a;
	float		b;

	y = -1;
	while (++y < vars->map->h)
	{
		x = -1;
		while (++x < vars->map->w)
		{
			a = ((vars->cam_dx - 400) + (x * 60));
			b = ((vars->cam_dy - 400) + (y * 60));
			a *= a;
			b *= b;
			if (a + b < 754 * 754) 
			{
				draw_frame(vars, vars->map->map[y][x], x, y);
				if (vars->map->map[y][x] == C)
					draw_frame(vars, 6 + vars->timers->coin_frame, x, y);
			}
		}
	}
}
