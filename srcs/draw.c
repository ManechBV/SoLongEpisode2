/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:42:12 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 07:46:53 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

void	ft_draw_map(t_vars *vars)
{
	int			x;
	int			y;
	mlx_color	pix[60 * 60];

	y = -1;
	while (++y < vars->map->h)
	{
		x = -1;
		while (++x < vars->map->w)
		{
			mlx_get_image_region(vars->mlx_vars->mlx, vars->imgs->tileset,
				vars->map->map[y][x] * 60, 0, 60, 60, pix);
			mlx_pixel_put_region(vars->mlx_vars->mlx,
				vars->mlx_vars->win, x * 60, y * 60, 60, 60, pix);
			if (vars->map->map[y][x] == C)
			{
				mlx_get_image_region(vars->mlx_vars->mlx, vars->imgs->tileset,
					(6 + vars->timers->coin_frame) * 60, 0, 60, 60, pix);
				mlx_pixel_put_region(vars->mlx_vars->mlx,
					vars->mlx_vars->win, x * 60, y * 60, 60, 60, pix);
			}
		}
	}
}
