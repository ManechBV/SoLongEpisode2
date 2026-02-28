/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:40:43 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 07:49:56 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

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
		if (vars->timers->coin_frame > 3)
			vars->timers->coin_frame = 0;
	}
}

void	update_loop(void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	update_timers(vars);
	mlx_clear_window(vars->mlx_vars->mlx, vars->mlx_vars->win,
		(mlx_color){.rgba = 0x101010FF});
	ft_draw_map(vars);
}
