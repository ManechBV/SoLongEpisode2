/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:39:28 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/27 00:14:22 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	
	if (ac < 2)
		return (ft_error("Not enough args."));
	if (read_and_parse(&vars, av[1]) != 0)
		return (-1);
	ft_printf("map:\n");
	for (int y = 0; y < vars.map->h; y++)
	{
		for (int x = 0; x < vars.map->w; x++)
			ft_printf(" %d ", vars.map->map[y][x]);
		ft_printf("\n");
	}
	/*
	if (ft_load_mlx(&vars) == 0)
	{
		mlx_loop(vars->mlx);
		ft_destroy_mlx(&vars);
	}
	*/
	free_vars(&vars);
	return (0);
}
