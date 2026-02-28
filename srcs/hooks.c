/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 07:40:43 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/28 08:26:40 by mabenois         ###   ########.fr       */
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

static void	move_player(t_vars *vars, int dx, int dy)
{
	int	x;
	int	y;
	int	target;

	y = -1;
	while (++y < vars->map->h)
	{
		x = -1;
		while (++x < vars->map->w)
		{
			if (vars->map->map[y][x] == P)
			{
				target = vars->map->map[y + dy][x + dx];
				if (target != 1)
				{
					vars->map->map[y + dy][x + dx] = P;
					vars->map->map[y][x] = vars->below_player;
					vars->below_player = target;
				}
				return ;
			}
		}
	}
}

void	key_hook(int key, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (key == 41)
		mlx_loop_end(vars->mlx_vars->mlx);
	if (key == 79)
		move_player(vars, 1, 0);
	if (key == 80)
		move_player(vars, -1, 0);
	if (key == 81)
		move_player(vars, 0, 1);
	if (key == 82)
		move_player(vars, 0, -1);
	if (vars->below_player == C)
	{
		vars->coin_left--;
		vars->below_player = 0;
	}
	if (vars->below_player == E && vars->coin_left == 0)
		mlx_loop_end(vars->mlx_vars->mlx);
}
