/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:33:17 by mabenois          #+#    #+#             */
/*   Updated: 2026/03/05 20:20:21 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

static int	ft_load_mlx3(t_vars *vars)
{
	vars->mlx_vars->target = mlx_new_image(vars->mlx_vars->mlx,
			vars->map->w * 60, vars->map->h * 60);
	if (!vars->mlx_vars->target)
		return (ft_destroy_mlx(vars));
	vars->mlx_vars->target_info.render_target = vars->mlx_vars->target;
	vars->mlx_vars->target_win = mlx_new_window(vars->mlx_vars->mlx,
			&vars->mlx_vars->target_info);
	mlx_set_fps_goal(vars->mlx_vars->mlx, 60);
	mlx_set_font_scale(vars->mlx_vars->mlx, "res/font.ttf", 69.0);
	vars->moves = 0;
	return (0);
}

static int	ft_load_mlx2(t_vars *vars)
{
	vars->mlx_vars->info.is_fullscreen = 0;
	vars->mlx_vars->win = mlx_new_window(vars->mlx_vars->mlx,
			&vars->mlx_vars->info);
	mlx_on_event(vars->mlx_vars->mlx, vars->mlx_vars->win, MLX_WINDOW_EVENT,
		window_hook, vars);
	mlx_on_event(vars->mlx_vars->mlx, vars->mlx_vars->win, MLX_KEYDOWN,
		key_hook, vars);
	mlx_add_loop_hook(vars->mlx_vars->mlx, update_loop, vars);
	vars->imgs = malloc(sizeof(t_imgs));
	if (!vars->imgs)
		return (ft_destroy_mlx(vars));
	vars->imgs->tileset = mlx_new_image_from_file(vars->mlx_vars->mlx,
			"res/tilesetx4.png", NULL, NULL);
	if (vars->imgs->tileset == NULL)
	{
		ft_error("Failed to load image.");
		return (ft_destroy_mlx(vars));
	}
	return (ft_load_mlx3(vars));
}

int	ft_load_mlx(t_vars *vars)
{
	vars->below_player = 0;
	vars->timers = malloc(sizeof(t_timers));
	if (!vars->timers)
		return (-1);
	vars->timers->coin_reset = 20;
	vars->timers->coin_timer = 20;
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
	return (ft_load_mlx2(vars));
}

int	ft_destroy_mlx(t_vars *vars)
{
	if (vars->mlx_vars->target_win != NULL)
		mlx_destroy_window(vars->mlx_vars->mlx, vars->mlx_vars->target_win);
	if (vars->mlx_vars->target != NULL)
		mlx_destroy_image(vars->mlx_vars->mlx, vars->mlx_vars->target);
	if (vars->imgs->tileset != NULL)
		mlx_destroy_image(vars->mlx_vars->mlx, vars->imgs->tileset);
	mlx_destroy_window(vars->mlx_vars->mlx, vars->mlx_vars->win);
	mlx_destroy_context(vars->mlx_vars->mlx);
	free(vars->mlx_vars);
	free(vars->imgs);
	free(vars->timers);
	return (-1);
}
