/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:33:17 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 07:25:36 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

int	ft_load_mlx(t_vars *vars)
{
	vars->timers = malloc(sizeof(t_timers));
	if (!vars->timers)
		return (-1);
	vars->timers->coin_reset = 40;
	vars->timers->coin_timer = 40;
	vars->timers->coin_frame = 0;
	vars->mlx_vars = malloc(sizeof(t_mlx_vars));
	if (!vars->mlx_vars)
	{
		free(vars->timers);
		return (-1);
	}
	ft_bzero(vars->mlx_vars, sizeof(t_mlx_vars));
	vars->mlx_vars->mlx = mlx_init();
	if (vars->mlx_vars->mlx == MLX_NULL_HANDLE)
	{
		free(vars->timers);
		free(vars->mlx_vars);
		return (-1);
	}
	vars->mlx_vars->info.title = "So fucking long";
	vars->mlx_vars->info.width = 800;
	vars->mlx_vars->info.height = 800;
	vars->mlx_vars->info.is_fullscreen = 0;
	vars->mlx_vars->win = mlx_new_window(vars->mlx_vars->mlx, &vars->mlx_vars->info);
	mlx_set_fps_goal(vars->mlx_vars->mlx, 60);
	mlx_on_event(vars->mlx_vars->mlx, vars->mlx_vars->win, MLX_WINDOW_EVENT,
				window_hook, vars);
	mlx_add_loop_hook(vars->mlx_vars->mlx, update_loop, vars);
	vars->imgs = malloc(sizeof(t_imgs));
	if (!vars->imgs)
		return (ft_destroy_mlx(vars));
	vars->imgs->tileset = mlx_new_image_from_file(
		vars->mlx_vars->mlx, "res/tilesetx4.png", NULL, NULL);
	return (0);
}

void	window_hook(int event, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (event == 0)
		mlx_loop_end(vars->mlx_vars->mlx);
}

static void	update_timers(t_vars *vars)
{
	vars->timers->coin_timer--;
	if (vars->timers->coin_timer < 0)
	{
		vars->timers->coin_timer = vars->timers->coin_reset;
		vars->timers->coin_frame++;
		if (vars->timers->coin_frame > 2)
			vars->timers->coin_frame = 0;
	}
}

void	update_loop(void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	update_timers(vars);
	mlx_clear_window(vars->mlx_vars->mlx, vars->mlx_vars->win,
					(mlx_color){ .rgba = 0x101010FF });
	ft_draw_map(vars);
}

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

int	ft_destroy_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_vars->mlx, vars->imgs->tileset);
	mlx_destroy_window(vars->mlx_vars->mlx, vars->mlx_vars->win);
	mlx_destroy_context(vars->mlx_vars->mlx);
	free(vars->mlx_vars);
	free(vars->imgs);
	free(vars->timers);
	return (-1);
}
